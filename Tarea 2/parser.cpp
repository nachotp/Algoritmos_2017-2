#include <vector>
#include <iostream>
#include <string>

#include "parser.h"
using namespace std;

punto::punto(unsigned long int xi,unsigned long int si){
  x = xi;
  s = si;
}

punto::punto(){
  x = 0;
  s = 0;
}

parser::parser(){
}

vector<punto> parser::interpretar(posicion edif){
  vector<punto> contorno;
  contorno.push_back(punto(edif[0],edif[1]));
  contorno.push_back(punto(edif[2],0));
  //cout << edif[0] << " " << edif[1] << " y " << edif[2] << " " << 0 << endl;
  return contorno;
}

string parser::colision(unsigned long int x,unsigned long int y, vector<punto> &contornos, int tamanio){
    int izq = 0;
    int mid;
    int der = tamanio - 1;
    punto posicion = punto(x,y);
    while (izq <= der) {
        mid = (izq + der) / 2;

        if (posicion.x == contornos[mid].x && posicion.s <= contornos[mid].s) {
          return "true";
        }
        else {
            if (contornos[mid].x > posicion.x) {
                der = mid - 1;
            } else {
                izq = mid + 1;
            }
        }
    }
    /*cout << "DRONE "<< posicion.x << " " << posicion.s << endl;
    cout << "IZQ "<< contornos[izq].x << " " << contornos[izq].s << endl;
    cout << "MID "<< contornos[mid].x << " " << contornos[mid].s << endl;
    cout << "DER "<< contornos[der].x << " " << contornos[der].s << endl;*/
    if(contornos[der].x == contornos[mid].x && contornos[der].s == contornos[mid].s){
      if(posicion.x >= contornos[mid].x && posicion.x <= contornos[izq].x){
        if(contornos[mid].s == 0)return "false";
        else if((posicion.s <= contornos[izq].s || posicion.s <= contornos[mid].s))return "true";
      }

    }
   else if(contornos[izq].x == contornos[mid].x && contornos[izq].s == contornos[mid].s){
     if(posicion.x >= contornos[der].x && posicion.x <= contornos[mid].x){
       if(contornos[der].s == 0)return "false";
       else if((posicion.s <= contornos[mid].s || posicion.s <= contornos[der].s) )return "true";
     }

   }
   return "false";
}

  //////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////
          //////////////////////////////////////////////////////////////////
            //////////////////////////////////////////////////////////////////
vector<punto>  parser::merge(vector<punto> &arreglo1, vector<punto> &arreglo2){
  unsigned int i = 0;
  unsigned int j = 0;
  punto last_red = punto(0,0);
  punto last_blue = punto(0,0);
  punto punto_red, punto_blue;
  punto newpto;
  vector<punto> finalarray;

  while(i < arreglo1.size() && j < arreglo2.size()){
    punto_red = arreglo1[i];
    punto_blue = arreglo2[j];

    if(punto_red.x < punto_blue.x){
      if (last_blue.s > punto_red.s && last_red.s > last_blue.s){
        newpto = punto(punto_red.x, last_blue.s);
        finalarray.push_back(newpto);
        last_red = punto_red;
        i++;
      }
      else if(last_blue.s > punto_red.s && last_red.s <= last_blue.s){
        last_red = punto_red;
        i++;
      }
      else{
        finalarray.push_back(punto_red);
        last_red = punto_red;
        i++;
      }
    }


    else if(punto_blue.x < punto_red.x){
      if(last_red.s > punto_blue.s && last_blue.s > last_red.s){
        newpto = punto(punto_blue.x, last_red.s);
        finalarray.push_back(newpto);
        last_blue = punto_blue;
        j++;
      }
      else if(punto_blue.s > last_red.s){
        finalarray.push_back(punto_blue);
        last_blue = punto_blue;
        j++;
      }
      else if(last_red.s > punto_blue.s && last_blue.s <= last_red.s){
        last_blue = punto_blue;
        j++;
      }
      else if(last_red.s == punto_blue.s){
        if(last_blue.s > last_red.s){
          finalarray.push_back(punto_blue);
        }
        last_blue = punto_blue;
        j++;
      }
    }

    else if(punto_red.x == punto_blue.x){
      if(punto_red.s >= punto_blue.s){
        finalarray.push_back(punto_red);
        last_red = punto_red;
        last_blue = punto_blue;
        i++;
        j++;
      }
      else if(punto_blue.s > punto_red.s && punto_blue.s != last_red.s){
        finalarray.push_back(punto_blue);
        last_red = punto_red;
        last_blue = punto_blue;
        i++;
        j++;
      }
    }
  }
  //una vez que se acaba uno de los arreglos empiezo a agregar todo el resto de puntos que quedaron
  while(i<arreglo1.size()){
    finalarray.push_back(arreglo1[i]);
    i++;
  }
  while(j<arreglo2.size()){
    finalarray.push_back(arreglo2[j]);
    j++;
  }

  return finalarray;
}
  //////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////
          //////////////////////////////////////////////////////////////////
            //////////////////////////////////////////////////////////////////
              //////////////////////////////////////////////////////////////////
                //////////////////////////////////////////////////////////////////


vector<punto> parser::mergeContours(vector<posicion> &posiciones){
  int izq = 0;
  int der = posiciones.size()-1;
  int mid = (izq+der)/2;
  vector<punto> ladoIzq, ladoDer;
  if (izq != der){
    ladoIzq = mergeContours(posiciones, izq, mid);
    ladoDer = mergeContours(posiciones, mid+1, der);
  } else {
    return interpretar(posiciones[mid]);
  }
  return merge(ladoIzq, ladoDer);
}

vector<punto> parser::mergeContours(vector<posicion> &posiciones, int izq, int der){
  int mid = (izq+der)/2;
  vector<punto> ladoIzq, ladoDer, setFinal;
  if (izq != der){
    ladoIzq = mergeContours(posiciones, izq, mid);
    ladoDer = mergeContours(posiciones, mid+1, der);
  } else {
    return interpretar(posiciones[mid]);
  }
  // MERGING
  return merge(ladoIzq, ladoDer);
}

/*
(1,3 3,0) (2,4 4,0) (5,2 8,0) (6,5 7,0) (8,4 9,0)
(1,3 2,4 4,0) (5,2 6,5 7,2 8,0) (8,4 9,0)
(1,3, 2,4, 4,0, 5,2 6,5, 7,2 8,0) (8,4 9,0)
(1,3, 2,4, 4,0, 5,2 6,5, 7,2 8,4 9,0)
*/

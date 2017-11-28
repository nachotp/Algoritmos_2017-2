#include <vector>
#include <iostream>
#include "parser.h"
using namespace std;

punto::punto(int xi, int si){
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

vector<punto> parser::merge(vector<punto> ladoIzq, vector<punto> ladoDer){
  cout << "MERGING"<< endl;
  unsigned int izq = 0, der = 0;
  vector<punto> unionContour;
  punto segInit, segFin, ptoDer, ptoDerSig;
  segInit = ladoIzq[izq];
  segFin = ladoIzq[izq+1];
  ptoDer = ladoDer[der];
  ptoDerSig = ladoDer[der+1];
  if (if segInit.x < ptoDer.x && segInit.s != ptoDer.s) {
    unionContour.push_back(segInit);
  }
  while (izq < ladoIzq.size()-1 && der < ladoDer.size()-1) {
    segInit = ladoIzq[izq];
    segFin = ladoIzq[izq+1];
    ptoDer = ladoDer[der];
    ptoDerSig = ladoDer[der+1];
    if (segInit.x <= ptoDer.x && ) {
      /* code */
    } else if (/* condition */) {
      /* code */
    } else {
      /* code */
    }
  }
}
  //////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////
          //////////////////////////////////////////////////////////////////
            //////////////////////////////////////////////////////////////////

void parser::function(vector<punto> arreglo1, vector<punto> arreglo2, vector<punto> finalarray){
  int i = 0;
  int j = 0;
  punto last_red = punto(0,0);
  punto last_blue = punto(0,0);
  punto punto_red, punto_blue;
  punto newpto;
  while(i < arreglo1.size() && j < arreglo2.size()){
    punto_red = arreglo1[i];
    punto_blue = arreglo2[j];

    if(punto_red.x < punto_blue.x && last_blue.s < punto_red.s){
      finalarray.push_back(punto_red);
      last_red = punto_red;
      i++;
    }


    else if(punto_blue.x < punto_red.x){
      if(last_red.s >= punto_blue.s){
        newpto = punto(punto_blue.x, last_red.s);
        finalarray.push_back(newpto);
      }
      else{
        finalarray.push_back(punto_blue);
        last_blue = punto_blue
      }
      j++;
    }

    else if(punto_red.x == punto_blue.x){
      if(punto_red.s <= punto_blue.s){
        finalarray.push_back(punto_blue);
        last_blue = punto_blue
      }
      else{
        finalarray.push_back(punto_red);
        last_red = punto_red;
      }
      j++;
      i++;
    }
    else{
      i++
      last_red = punto_red;
    }

    //last_blue = punto_blue;
  }
  //una vez que se acaba uno de los arreglos empiezo a agregar todo el resto de puntos que quedaron
  for(i; i<arreglo1.size(); i++){
    finalarray.push_back(arreglo[i]);
  }
  for(j; j<arreglo2.size(); j++){
    finalarray.push_back(arreglo2[i]);
  }
}

  //////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////
      //////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////
          //////////////////////////////////////////////////////////////////
            //////////////////////////////////////////////////////////////////
              //////////////////////////////////////////////////////////////////
                //////////////////////////////////////////////////////////////////

  while (izq < ladoIzq.size()) {
    unionContour.push_back(ladoIzq[izq]);
    izq++;
  }
  while (der < ladoDer.size()) {
    unionContour.push_back(ladoDer[der]);
    der++;
  }

  return unionContour;
}

vector<punto> parser::mergeContours(vector<posicion> posiciones){
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

vector<punto> parser::mergeContours(vector<posicion> posiciones, int izq, int der){
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

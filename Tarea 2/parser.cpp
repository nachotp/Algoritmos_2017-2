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

void parser::funcion(vector<punto> arreglo1, vector<punto> arreglo2, int i, int j, vector<punto> &finalarray){
  punto;
  while(i < arreglo1.size()-1 && j < arreglo2.size()-1){
    punto1 = arreglo1[i];
    punto2 = arreglo1[i+1];
    punto3 = arreglo2[j];
    punto4 = arreglo2[j+1];

    if(punto1.x < punto3.x  < punto2.x && punto1.s > punto3.s && punto3.s > punto2.s){
      if(punto2.x < punto4.x){
        newpto = (punto2.x, punto3.h);
        add(newpto);
      }
    }
    else if(punto1.x <= punto3.x < punto2.x && punto1.s < punto3.s){
      add(punto3); //ojo, quizas hay que borrar el pto que se pone al inicio porque se "sobreescribe"
      if(punto4.x < punto2.x && punto4.s < punto1.s){
        newpto = (punto4.x, punto1.h);
        add(newpto);
      }
    }


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

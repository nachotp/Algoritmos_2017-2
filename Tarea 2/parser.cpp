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
  while (izq < ladoIzq.size()-1 && der < ladoDer.size()-1) {
    if (ladoIzq[izq].x < ladoDer[der].x) {
      unionContour.push_back(ladoIzq[izq]);
      if(ladoDer[der] < ladoIzq[izq+1]){
        unionContour.push_back(ladoDer[der]);
      }
      else if(ladoDer[der] == ladoIzq[izq+1]){
        unionContour.push_back(ladoDer[der+1]);
      }
      else{
        unionContour.push_back(ladoDer[der]);
        unionContour.push_back(ladoDer[der+1]);
      }
    }
  }

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

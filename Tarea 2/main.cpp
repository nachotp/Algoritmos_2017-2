#include <iostream>
#include <string>
#include "parser.h"
using namespace std;


int main(int argc, char **argv) {
  unsigned int numEdificios, numDrones;
  unsigned long int X, Y;
  parser traductor;
  vector<punto> contorno;
  string prueba;
  unsigned long int  L, H, R;
  ios::sync_with_stdio(false);
  vector<posicion> posiciones;
  cin >> numEdificios;
  for (size_t i = 0; i < numEdificios; ++i) {
    cin >> L >> H >> R;
    posiciones.push_back({L,H,R});
  }
  contorno = traductor.mergeContours(posiciones);

  cout << contorno.size() << endl;
  for (punto P : contorno){
    cout << P.x << " " << P.s << endl;
  }

  cin >> numDrones;
  cout << numDrones << endl;
  for (size_t i = 0; i < numDrones; ++i) {
    cin >> X >> Y;
    prueba = traductor.colision(X, Y, contorno, contorno.size());
    cout << prueba << endl;
  }

  return 0;
}

#include <iostream>
#include <string>
#include "parser.h"
using namespace std;


int main(int argc, char **argv) {
  unsigned int numEdificios, numDrones, X, Y;
  parser traductor;
  vector<punto> contorno;
  int  L, H, R;
  ios::sync_with_stdio(false);
  vector<posicion> posiciones;
  cin >> numEdificios;
  for (size_t i = 0; i < numEdificios; ++i) {
    cin >> L >> H >> R;
    posiciones.push_back({L,H,R});
  }
  cout << "weas leidas" << endl;
  contorno = traductor.mergeContours(posiciones);

  cout << contorno.size() << endl;
  for (punto P : contorno){
    cout << P.x << " " << P.s << endl;
  }

  cin >> numDrones;
  for (size_t i = 0; i < numDrones; ++i) {
    cin >> X >> Y;
    // consultar drones
  }

  return 0;
}

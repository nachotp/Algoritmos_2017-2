#include <iostream>
#include <string>
#include "parser.h"
using namespace std;


int main(int argc, char **argv) {
  unsigned int numEdificios, numDrones, X, Y;
  parser traductor;
  int  L, H, R;
  ios::sync_with_stdio(false);
  vector<posicion> posiciones;
  cin >> numEdificios;
  for (size_t i = 0; i < numEdificios; ++i) {
    cin >> L >> H >> R;
    posiciones.push_back({L,H,R});
  }
  cout << "weas leidas" << endl;
  traductor.mergeContours(posiciones);

  cin >> numDrones;
  for (size_t i = 0; i < numDrones; ++i) {
    cin >> X >> Y;
    // consultar drones
  }

  return 0;
}

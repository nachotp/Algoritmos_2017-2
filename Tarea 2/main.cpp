#include <iostream>
#include <string>

using namespace std;


int main(int argc, char **argv) {
  int numEdificios, L, H, R, numDrones, X, Y;
  ios::sync_with_stdio(false);

  cin >> numEdificios;
  for (size_t i = 0; i < numEdificios; ++i) {
    cin >> L >> H >> R;
  }

  // hacer magia con los edificios

  cin >> numDrones;
  for (size_t i = 0; i < numDrones; ++i) {
    cin >> X >> Y;
    // consultar drones
  }
  return 0;
}

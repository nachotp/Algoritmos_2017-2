#include <iostream>
#include <string>
#include "funciones.h"
using namespace std;


int main(int argc, char **argv) {

  string str;
  ios::sync_with_stdio(false);
  while (cin >> str) {
    cout << palindromeSubsec(str) << endl;
  }

  return 0;
}

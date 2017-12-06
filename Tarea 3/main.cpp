#include <iostream>
#include <string>
#include "funciones.h"
using namespace std;


int main(int argc, char **argv) {

  string str;

  while (cin >> str) {
    cout << palindromeSubsec(str) << endl;
  }

  return 0;
}

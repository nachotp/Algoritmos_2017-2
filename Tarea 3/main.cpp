#include <iostream>
#include <string>
#include "funciones.h"
using namespace std;


int main(int argc, char **argv) {

  string str;
  string str2;
  ios::sync_with_stdio(false);

  while (cin >> str) {
    str2 = str;
    reverseStr(str2);
    cout << palindromeSubsec(str,str2) << endl;
  }

  return 0;
}

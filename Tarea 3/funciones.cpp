#include <vector>
#include <iostream>
#include <string>

#include "funciones.h"
using namespace std;

int palindromeSubsec(string &palabra, string &palabra_inv){
  int n = palabra.length();
  int i, j;
  int L[n+1][n+1];

   // Strings of length 1 are palindrome of lentgh 1
    for (i=0; i<=n; i++){

      for (j=0; j<=n; j++){

        if (i == 0 || j == 0){
              L[i][j] = 0;
        }

        else if (palabra[i-1] == palabra_inv[j-1]){
          L[i][j] = L[i-1][j-1] + 1;
        }

        else{
          L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
      }
    }
    return L[n][n];
}

void reverseStr(string &str)
{
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i=0; i<n/2; i++)
       swap(str[i], str[n-i-1]);
}

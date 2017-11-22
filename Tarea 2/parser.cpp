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
  posArray.push_back(punto());
}

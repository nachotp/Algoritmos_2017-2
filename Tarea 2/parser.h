#ifndef PARSER
#define PARSER
#include <array>
#include <vector>
using namespace std;

typedef array<int, 3> posicion;

class punto {
public:
  int x, s;
  punto(int xi, int si);
  punto();
};

class parser {
private:
  vector<punto> posArray;
  int edifAnterior[3];
  punto tempPunto;
public:
  parser();
};


#endif

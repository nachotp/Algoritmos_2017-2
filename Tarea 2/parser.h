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

public:
  parser();
  vector<punto> interpretar(posicion);
  vector<punto> merge(vector<punto> ladoIzq, vector<punto> ladoDer);
  vector<punto> mergeContours(vector<posicion> posiciones);
  vector<punto> mergeContours(vector<posicion> posiciones, int izq, int der);

};


#endif

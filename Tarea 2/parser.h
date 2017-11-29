#ifndef PARSER
#define PARSER
#include <array>
#include <vector>
using namespace std;

typedef array<unsigned long int, 3> posicion;

class punto {
public:
  unsigned long int x, s;
  punto(unsigned long int xi, unsigned long int si);
  punto();
};

class parser {
private:

public:
  parser();
  vector<punto> interpretar(posicion);
  vector<punto> merge(vector<punto> &arreglo1, vector<punto> & arreglo2);
  vector<punto> mergeContours(vector<posicion> &posiciones);
  vector<punto> mergeContours(vector<posicion> &posiciones, int izq, int der);
  bool colision(unsigned long int x,unsigned long int y, vector<punto> &contornos, int tamanio);

};


#endif

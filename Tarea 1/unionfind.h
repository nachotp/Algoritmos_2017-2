#ifndef UNIONFIND
#define UNIONFIND

#include <vector>
using namespace std;


typedef vector<int> vi;

class persona {
public:
    int fobia;
    persona(int f);
    persona();
};

class UnionFind {
private:
  vi p, rank, setSize, fsets;
  vector <vi > fobiaArrays;
  vector<persona> arreglo;
  int numSets;
public:
  UnionFind(int N);
  void addPersona(int pos, persona person);
  int findSet(int i);
  bool isSameSet(int i, int j);
  void unionSet(int i, int j);
  int numDisjointSets();
  int sizeOfSet(int i);
  void setFobiaArrays(int fobias);
};


#endif

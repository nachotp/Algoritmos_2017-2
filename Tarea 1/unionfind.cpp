
#include <vector>
#include <iostream>
#include <algorithm>
#include "unionfind.h"
using namespace std;

persona::persona(int f){
    fobia = f;
}

persona::persona(){
    fobia = -1;
}

UnionFind::UnionFind(int N) {
  setSize.assign(N, 1);
  arreglo.resize(N);
  numSets = N;
  rank.assign(N, 0);
  p.assign(N, 0);
  for (int i = 0; i < N; i++) p[i] = i;
}

void UnionFind::addPersona(int pos, persona person){
    arreglo[pos]= person;
}

int UnionFind::findSet(int i) {
  return (p[i] == i) ? i : (p[i] = findSet(p[i]));
}

bool UnionFind::isSameSet(int i, int j) {
  return findSet(i) == findSet(j);
}

void UnionFind::unionSet(int i, int j) {
  if (!isSameSet(i, j)) {
    numSets--;
    int x = findSet(i), y = findSet(j);
  // rank is used to keep the tree short
    if (rank[x] > rank[y]) {
      p[y] = x;
      setSize[x] += setSize[y];
    }
    else {
      p[x] = y;
      setSize[y] += setSize[x];
      if (rank[x] == rank[y]) rank[y]++;
    }
  }
}

int UnionFind::numDisjointSets() {
  return numSets;
}

int UnionFind::sizeOfSet(int i) {
  return setSize[findSet(i)];
}

vector<vi > UnionFind::setFobiaArrays(int fobias){
  int currSet, set, pos;
  vi::iterator it;
  fobiaArrays.resize(numDisjointSets());
  for (int i = 0; i < numDisjointSets(); ++i) {
    fobiaArrays[i].resize(fobias);
  }
  cout << "espacio asignado "<<fobias << endl;
  currSet = set = findSet(0);
  pos = 0;
  fsets.push_back(set);
  cout << fsets[0]<< " "<< currSet << endl;
  for (size_t j = 0; j < p.size(); j++) {
    set = findSet(j);
    cout << "set "<< set << " para "<<j<< " pos "<<pos<<endl;
    if (currSet != set) {
      cout << "BLEH"<<endl;
      currSet = set;
      it = find(fsets.begin(),fsets.end(),set);
      if(it!=fsets.end()){
        pos = it - fsets.end();
      } else {
        fsets.push_back(set);
        pos = fsets.size()-1;
      }
    }
    fobiaArrays[pos][(arreglo[j].fobia)]++;
  }
  return fobiaArrays;
}


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
    arreglo[pos] = person;

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

void UnionFind::setFobiaArrays(int fobias){
  int currSet, set, pos;
  vi::iterator it;
  fobiaArrays.resize(numDisjointSets());
  for (int i = 0; i < numDisjointSets(); ++i) {
    fobiaArrays[i].assign(fobias,0);
  }
  currSet = findSet(0);
  set = currSet;
  pos = 0;
  fsets.push_back(set);
  for (size_t j = 0; j < p.size(); j++) {
    set = findSet(j);
    if (currSet != set) {
      currSet = set;
      it = find(fsets.begin(),fsets.end(),set);
      if(it!=fsets.end()){
        pos = distance(fsets.begin(), it);
      } else {
        fsets.push_back(set);
        pos = fsets.size()-1;
      }
    }
    fobiaArrays[pos][(arreglo[j].fobia)-1]++;
  }

  for (vector<int> com : fobiaArrays){
    int fobiaMax = 0;
    int pos = 0;
    for(size_t i = 0; i < com.size(); ++i){
        if (com[i] > fobiaMax){
            fobiaMax = com[i];
            pos = i;
        }
    }
    cout << pos+1 << endl;
  }
}

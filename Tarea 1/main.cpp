#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "unionfind.h"
using namespace std;


int main( int argc, char **argv) {
    unsigned int numPersonas, numArcos, fobia = 0, fobiaMax = 0, p1, p2;
    ios::sync_with_stdio(false);
    cin >> numPersonas;
    UnionFind UF(numPersonas);
    for(size_t i = 0; i < numPersonas; ++i){
        cin >> fobia;
        UF.addPersona(i, persona(fobia));
        if (fobia > fobiaMax) fobiaMax = fobia;
    }
    cin >> numArcos;
    for(size_t i = 0; i < numArcos; ++i){
        cin >> p1 >> p2;
        UF.unionSet(p1-1, p2-1);
    }

    cout << UF.numDisjointSets() << endl;
    UF.setFobiaArrays(fobiaMax);
}

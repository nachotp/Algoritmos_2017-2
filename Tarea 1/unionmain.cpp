#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
//#include <utility>

#include "unionfind.h"
using namespace std;


int main( int argc, char **argv) {
    unsigned int numPersonas, numArcos, fobia = 0, fobiaMax =0, p1, p2;
    ios::sync_with_stdio(false);
    cin >> numPersonas;
    UnionFind UF(numPersonas);
    cout << "Union find inicializado" << endl;
    for(size_t i = 0; i < numPersonas; ++i){
        cin >> fobia;
        UF.addPersona(i, persona(fobia));
        if (fobia > fobiaMax) fobiaMax = fobia;
    }
    cin >> numArcos;
    cout << "Personas creadas" << endl;
    for(size_t i = 0; i < numArcos; ++i){
        cin >> p1 >> p2;
        UF.unionSet(p1-1, p2-1);
    }
    cout << "Arcos creados" << endl;

    int max;
    vector< vector<int> > commies = UF.setFobiaArrays(fobiaMax);

}

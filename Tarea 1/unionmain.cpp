#include <iostream>
#include <string>
#include <vector>
#include <map>
//#include <utility>

#include "unionfind.h"
using namespace std;


int main( int argc, char **argv) {
    unsigned int numPersonas, numArcos, fobia, p1, p2;
    cin >> numPersonas;
    UnionFind UF(numPersonas);
    cout << "Union find inicializado" << endl;
    for(size_t i = 0; i < numPersonas; ++i){
        cin >> fobia;
        graph.addPersona(i, persona(fobia));
    }
    cin >> numArcos;
    cout << "Personas creadas" << endl;
    for(size_t i = 0; i < numArcos; ++i){
        cin >> p1 >> p2;
        graph.crearArco(p1-1, p2-1);
    }

    cout << "Arcos creados" << endl;

    int fobiaMax, max;
    //graph.printGrafo();
    vector< vector<persona> > commies = graph.dfs2();

    cout << "Comunidades creadas" << endl;
    map<int, int> fobiaMap;
    persona tp(-1);
    cout << commies.size() << endl;
    for(size_t comu = 0; comu < commies.size(); ++comu){
        fobiaMax = -1;
        max = -1;
        for(size_t i = 0; i < commies[comu].size(); ++i){
            tp = commies[comu][i];
            if (fobiaMap.find(tp.fobia) == fobiaMap.end()){
                fobiaMap[tp.fobia] = 0;
            }
            fobiaMap[tp.fobia] = fobiaMap[tp.fobia] + 1;
        }
        for( map<int,int>::iterator ii=fobiaMap.begin(); ii!=fobiaMap.end(); ++ii){
            if ((*ii).second > max){
                max = (*ii).second;
                fobiaMax = (*ii).first;
            }
        }
        fobiaMap.clear();
        cout << fobiaMax << endl;
    }
}

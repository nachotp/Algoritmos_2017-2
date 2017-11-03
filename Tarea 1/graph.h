#ifndef GRAFO
#define GRAFO

#include <vector>
#include <stdlib.h>
using namespace std;

class persona {
public:
    int fobia;
    bool visited;
    int comunidad;
    persona(int f);
    persona();
    void visitar();
    bool visitado();
    void desvisitar();
};

class grafo {
    vector <persona> arreglo;
    vector < vector<int> > lista_ady;
public:
    grafo(int n);
    vector< vector<persona> > dfs();
    vector< vector<persona> > dfs2();
    void addPersona(int pos, persona person);
    void crearArco(int p1, int p2);
    void printGrafo();
    void desmarcar();
    bool hayArco(int p1, int p2);

};

#endif

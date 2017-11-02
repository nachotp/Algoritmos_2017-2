#include <vector>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include "graph.h"

using namespace std;

persona::persona(int f){
    fobia = f;
    comunidad = 0;
    visited = false;
}

persona::persona(){
    fobia = -1;
    visited = false;
}

void persona::visitar(){
    visited = true;
}

void persona::desvisitar(){
    visited = false;
}

bool persona::visitado(){
    return visited;
}

grafo::grafo(int n){
    arreglo.resize(n);
    lista_ady.resize(n);
}

void grafo::crearArco(int p1, int p2){
    lista_ady[p1].push_back(p2);
    lista_ady[p2].push_back(p1);
}

void grafo::addPersona(int pos, persona person){
    arreglo[pos]= person;
}

void grafo::printGrafo(){
    cout << "Grafo: "<< arreglo.size() <<endl;
    for (size_t i = 0; i < arreglo.size(); ++i){
        cout << i+1 << ": ";
        for (size_t j = 0; j < lista_ady[i].size(); ++j){
            cout << lista_ady[i][j]+1 << " ";
        }
        cout << endl;
    }
}

void grafo::desmarcar(){
    for (size_t i = 0; i < arreglo.size(); ++i) arreglo[i].desvisitar();
}

bool grafo::hayArco(int p1, int p2){
    return find(lista_ady[p1].begin(), lista_ady[p1].end(), p2) != lista_ady[p1].end();
}

vector< vector<persona> > grafo::dfs(){
    vector< vector<persona> > comunidades;
    stack<int> s;
    int i;
    int comunidad = 0;
    desmarcar();
    cout << "desmarcado todo"<< endl;
    //if(x == required) return;
    for (size_t person = 0; person < arreglo.size(); person++){
        
        if (!arreglo[person].visitado()){
            comunidades.push_back(vector<persona>());
            cout << "Depth first Search starting for community ";
            cout << comunidad << ":" << endl;
            s.push(person);
            arreglo[person].visitar();
            comunidades[comunidad].push_back(arreglo[person]);
            while(!s.empty()){
                int k = s.top();
                s.pop();
                cout<<k+1<<" ";
                for (i = arreglo.size(); i >= 0 ; --i)
                    if (hayArco(k, i) && !arreglo[i].visitado()) {
                        s.push(i);
                        arreglo[i].visitar();
                        comunidades[comunidad].push_back(arreglo[i]);
                    }
            }
            cout<<endl;
            ++comunidad;
        }
        
    }
    return comunidades;
}
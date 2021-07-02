#include "queue"
#include "DirectedGraph.h"
#include <unordered_map>
#include <tuple>
using namespace std;




template<typename TV,typename TE>
class prim{

private:
    DirectedGraph<TV,TE>* G;

public:
    prim() = default;
    prim(Graph<TV,TE>* &grafo,string id){
        auto tamanio = grafo->vertexes.size();
        unordered_map<string,int> vertex;
        G = new DirectedGraph<TV,TE>;
        unordered_map<string,tuple<string,int,bool>> padres;



        for(auto i: grafo->vertexes){
            if (i.first == id){
                tuple<string,int,bool> aux (id,-1, true);
                padres[id] = aux;

            }
            else{
                tuple<string,int,bool> aux (i.first,INT32_MAX,false);
                padres[i.first] = aux;
            }
        }
        for(auto i:  grafo->vertexes){
            auto x = i.second->data;
            vertex[i.first] = x;
        }
        auto aux = grafo->vertexes[id];
        string ax;
        for (int tam = 0; tam < tamanio; ++tam) {
            for (auto i:aux->edges) {
                ax = i->vertexes[1]->id;
                auto pesop = i->weight;
                auto x = padres[ax];
                if (get<1>(x)  > pesop && !get<2>(x)) {
                    tuple<string,int,bool> temp(id,pesop,true);
                    padres[ax] = temp;
                }

            }
            id = ax;
            aux = grafo->vertexes[id];
        }

        for (auto i:padres) {
            auto x = i.second;
            if(get<1>(x) == -1){

                G->insertVertex(i.first,vertex[i.first]);
            }
            else if (get<0>(x) != i.first && get<1>(x) < INT32_MAX && G->findById(get<0>(x))){
                G->insertVertex(i.first,vertex[i.first]);
                G->createEdge(get<0>(x),i.first,get<1>(x));
            }
            else if (get<0>(x) != i.first && get<1>(x) < INT32_MAX && !G->findById(get<0>(x))){
                G->insertVertex(i.first,vertex[i.first]);
                G->insertVertex(get<0>(x),vertex[i.first]);
                G->createEdge(get<0>(x),i.first,get<1>(x));
            }
        }

    }

    DirectedGraph<TV,TE>* apply(){
        return G;
    }
};
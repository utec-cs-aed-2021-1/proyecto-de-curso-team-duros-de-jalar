#include <stack>
#include <unordered_set>
#include "../DirectedGraph.h"
#include "../UndirectedGraph.h"
using namespace std;


template<typename TV, typename TE>
class dfs{
private:
    DirectedGraph<TV,TE>* G;
public:
    dfs() = default;
    dfs(Graph<TV,TE>* &grafo, string vertexid) {
        std::unordered_set<string> visited;
        std::stack<pair<string ,Vertex<TV,TE>*>> pila;

        auto aux = grafo->vertexes[vertexid];
        G = new DirectedGraph<TV,TE>;
        G->insertVertex(vertexid, aux->data);

        visited.insert(vertexid); //PREGUNTAR AL PROFE

        for(auto& i : aux->edges){
            Vertex<TV,TE>* ax = i->vertexes[1];
            if(visited.find(ax->id) ==visited.end()){
                pila.push(make_pair( aux->id, ax));
            }
        }

        while(!pila.empty()){
            pair<string ,Vertex<TV,TE>*> res = pila.top();
            pila.pop();
            string id; Vertex<TV,TE>* to_insert;
            id = res.first;
            to_insert = res.second;

            if(visited.find(to_insert->id) ==visited.end()) {
                visited.insert(to_insert->id);
                G->insertVertex(to_insert->id, to_insert->data);
                G->createEdge(id, to_insert->id, 1);
            }

            for(auto& i : to_insert->edges){
                Vertex<TV,TE>* ax = i->vertexes[1];
                if(visited.find(ax->id) ==visited.end()){
                    pila.push(make_pair(to_insert->id,ax));
                }
            }
        }
    }

    DirectedGraph<TV,TE>* apply(){
        return G;
    }

};
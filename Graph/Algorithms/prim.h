#include "queue"
#include "UndirectedGraph.h"
#include <unordered_map>
#include <tuple>
using namespace std;


typedef tuple<string ,int,string> par;
struct Compare{
    bool operator()(const par& a, const par& b){
        if(get<1>(a) > get<1>(b)){
            return true;
        }
        return false;
    }
};



template<typename TV,typename TE>
class prim{

private:
    UnDirectedGraph<TV,TE>* primm;
    int cost;

public:
    prim() = default;
    prim(Graph<TV,TE>* &grafo,const string& id){

        priority_queue<par, vector<par>, Compare> cont;
        unordered_set<string> visited;
        primm = new UnDirectedGraph<TV,TE>;

        primm->insertVertex(id,grafo->vertexes[id]->data);
        visited.insert(id);

        Vertex<TV,TE>* temp = grafo->vertexes[id];
        for(auto i: temp->edges){
            Vertex<TV,TE>* ax = i->vertexes[1];
            if(visited.find(ax->id) ==visited.end()){
                cont.push(make_tuple(id,i->weight,ax->id));
            }
        }

        cost =0;

        while (!cont.empty()){
            string origin = get<0>(cont.top());
            int mcost  = get<1>(cont.top());
            string idd = get<2>(cont.top());
            cont.pop();

            if(visited.find(idd) == visited.end()){
                cost += mcost;
                visited.insert(idd);
                primm->insertVertex(idd, grafo->vertexes[idd]->data);
                primm->createEdge(origin,idd, mcost);
                Vertex<TV,TE>* nuevo = grafo->vertexes[idd];

                for(auto i: nuevo->edges){
                    Vertex<TV,TE>* ax = i->vertexes[1];
                    if(visited.find(ax->id) ==visited.end()){

                        cont.push(make_tuple(idd,i->weight,ax->id));
                    }
                }
            }

        }

    }

    UnDirectedGraph<TV,TE>* apply(){
        return primm;
    }
    int mstcost(){
        return cost;
    }
};

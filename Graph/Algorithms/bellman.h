#include <queue>
#include <unordered_set>
#include <unordered_map>
#include "..\DirectedGraph.h"

template<typename TV, typename TE>
class bellmanford{
    unordered_map<string, int> distance;
    unordered_map<string, pair<string,TE>> papi;
    DirectedGraph<TV,TE>* result;
    bool nonnegative{};
public:
    bellmanford(DirectedGraph<TV,TE>* grp, const string& start){
        Vertex<TV,TE>* init = grp->vertexes[start];
        for(auto i = grp->vertexes.begin(); i!= grp->vertexes.end(); i++){
            distance[i->first]= INT_MAX;
        }
        distance[init->id] = 0;
        unordered_set<string> stin;
        queue<string> in;
        in.push(init->id);
        stin.insert(init->id);
        while (!in.empty()){
            string cur = in.front();
            Vertex<TV,TE>* current = grp->vertexes[in.front()];
            in.pop();
            stin.erase(init->id);
            for(auto i = current->edges.begin(); i != current->edges.end(); i++){
                string adj = (*i)->vertexes[1]->id;
                if(distance[cur] + (*i)->weight < distance[adj]){
                    distance[adj] =  distance[cur] + (*i)->weight;
                    papi[adj] = make_pair(cur,(*i)->weight) ;
                    if(stin.find(adj) == stin.end()){
                        in.push(adj);
                        stin.insert(adj);
                    }
                }
            }
        }
         for(auto i = papi.begin(); i != papi.end(); i++){
            if(distance[i->first] != INT_MAX && distance[i->second.first]  > distance[i->first] +  i->second.second){
                cout<<"HAY CICLOS NEGATIVOS."<<endl;
                return;
            }
        }
        making_graph(grp);
    }
    void making_graph(Graph<TV,TE>* grp){
    result = new DirectedGraph<TV,TE>;
    for(auto i = papi.begin(); i!=papi.end(); i++){
        result->insertVertex(i->first, grp->vertexes[i->first]->data);
        result->insertVertex(i->second.first, grp->vertexes[i->second.first]->data);
        result->createEdge(i->second.first, i->first, i->second.second);
    }
    }
    DirectedGraph<TV,TE>* apply(){
    return result;
}
};

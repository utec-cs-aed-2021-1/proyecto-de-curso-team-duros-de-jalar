#include "../UndirectedGraph.h"
#include "../DirectedGraph.h"
#include <unordered_map>
#include <unordered_set>

template <typename TV, typename  TE>
string Distancemin (Graph<TV,TE>* & grafo, unordered_map<string,int>& dist, unordered_map<string,bool>& spt){
    int num = INT32_MAX;
    string index;

    for (auto & i : grafo->vertexes) {

        if (dist[i.second->id] <= num && !spt[i.second->id]){
            num = dist[i.second->id],
            index = i.second->id;
        }
    }
    return index;
}
template <typename TV, typename  TE>
string Distancemin (UnDirectedGraph<TV,TE>* & grafo, unordered_map<string,int>& dist, unordered_map<string,bool>& spt){
    int num = INT32_MAX;
    string index;

    for (auto & i : grafo->vertexes) {

        if (dist[i.second->id] <= num && !spt[i.second->id]){
            num = dist[i.second->id],
            index = i.second->id;
        }
    }
    return index;
}

template <typename TV, typename  TE>
string Distancemin (DirectedGraph<TV,TE>* & grafo, unordered_map<string,int>& dist, unordered_map<string,bool>& spt){
    int num = INT32_MAX;
    string index;

    for (auto & i : grafo->vertexes) {

        if (dist[i.second->id] <= num && !spt[i.second->id]){
            num = dist[i.second->id],
                    index = i.second->id;
        }
    }
    return index;
}




template <typename TV, typename  TE>

class dijkstra{
    DirectedGraph<TV,TE>* dijksstra;

public:
    dijkstra() = default;
    dijkstra(Graph<TV,TE>* & grafo, const string& id){
        dijksstra = new DirectedGraph<TV,TE>;
        unordered_map<string,int> dist;
        unordered_map<string,bool> sptSet;
        unordered_map<string,pair<Vertex<TV,TE>*,string>> distancia_vertice;

        for(auto &i : grafo->vertexes){
            if (i.second->id == id) {
                dist[i.second->id] = 0;
            }
            else {
                dist[i.second->id] = INT32_MAX;
            }
            sptSet[i.second->id] = false;
            pair<Vertex<TV,TE>*,string> aux (i.second,i.second->id);
            distancia_vertice[i.second->id] = aux;
            dijksstra->insertVertex(i.second->id,i.second->data);
        }
        for (int i = 0; i < grafo->vertexes.size() - 1; ++i) {
            string u = Distancemin(grafo,dist,sptSet);
            sptSet[u] = true;
            for (auto j : grafo->vertexes) {
                if (!sptSet[j.second->id] && dist[u] != INT32_MAX){
                    auto aristas = distancia_vertice[u].first;
                    for (auto k : aristas->edges) {
                        if (k->vertexes[1]->id == j.second->id){
                            if (dist[j.second->id] > dist[u] + k->weight){
                                dist[j.second->id] = dist[u] + k->weight;
                                pair<Vertex<TV,TE>*,string> aux(distancia_vertice[j.second->id].first,u);
                                distancia_vertice[j.second->id] = aux;
                            }

                        }
                    }
                };
            }
        }
        auto x = *distancia_vertice.begin();
        for(auto& i : distancia_vertice){
            if (i.first !=  x.first) {
                auto j = i.second;
                auto size = dist[i.second.first->id];
                if (j.first->id != j.second)
                    size -= dist[j.second];
                dijksstra->createEdge(j.second,j.first->id,size);
            }
        }
    }

    dijkstra(UnDirectedGraph<TV,TE>* & grafo, const string& id){
        dijksstra = new DirectedGraph<TV,TE>;
        unordered_map<string,int> dist;
        unordered_map<string,bool> sptSet;
        unordered_map<string,pair<Vertex<TV,TE>*,string>> distancia_vertice;

        for(auto &i : grafo->vertexes){
            if (i.second->id == id) {
                dist[i.second->id] = 0;
            }
            else {
                dist[i.second->id] = INT32_MAX;
            }
            sptSet[i.second->id] = false;
            pair<Vertex<TV,TE>*,string> aux (i.second,i.second->id);
            distancia_vertice[i.second->id] = aux;
            dijksstra->insertVertex(i.second->id,i.second->data);
        }
        for (int i = 0; i < grafo->vertexes.size() - 1; ++i) {
            string u = Distancemin(grafo,dist,sptSet);
            sptSet[u] = true;
            for (auto j : grafo->vertexes) {
                if (!sptSet[j.second->id] && dist[u] != INT32_MAX){
                    auto aristas = distancia_vertice[u].first;
                    for (auto k : aristas->edges) {
                        if (k->vertexes[1]->id == j.second->id){
                            if (dist[j.second->id] > dist[u] + k->weight){
                                dist[j.second->id] = dist[u] + k->weight;
                                pair<Vertex<TV,TE>*,string> aux(distancia_vertice[j.second->id].first,u);
                                distancia_vertice[j.second->id] = aux;
                            }

                        }
                    }
                };
            }
        }
        auto x = *distancia_vertice.begin();
        for(auto& i : distancia_vertice){
            if (i.first !=  x.first) {
                auto j = i.second;
                auto size = dist[i.second.first->id];
                if (j.first->id != j.second)
                    size -= dist[j.second];
                dijksstra->createEdge(j.second,j.first->id,size);
            }
        }
    }

    dijkstra(DirectedGraph<TV,TE>* & grafo, const string& id){
        dijksstra = new DirectedGraph<TV,TE>;
        unordered_map<string,int> dist;
        unordered_map<string,bool> sptSet;
        unordered_map<string,pair<Vertex<TV,TE>*,string>> distancia_vertice;

        for(auto &i : grafo->vertexes){
            if (i.second->id == id) {
                dist[i.second->id] = 0;
            }
            else {
                dist[i.second->id] = INT32_MAX;
            }
            sptSet[i.second->id] = false;
            pair<Vertex<TV,TE>*,string> aux (i.second,i.second->id);
            distancia_vertice[i.second->id] = aux;
            dijksstra->insertVertex(i.second->id,i.second->data);
        }
        for (int i = 0; i < grafo->vertexes.size() - 1; ++i) {
            string u = Distancemin(grafo,dist,sptSet);
            sptSet[u] = true;
            for (auto j : grafo->vertexes) {
                if (!sptSet[j.second->id] && dist[u] != INT32_MAX){
                    auto aristas = distancia_vertice[u].first;
                    for (auto k : aristas->edges) {
                        if (k->vertexes[1]->id == j.second->id){
                            if (dist[j.second->id] > dist[u] + k->weight){
                                dist[j.second->id] = dist[u] + k->weight;
                                pair<Vertex<TV,TE>*,string> aux(distancia_vertice[j.second->id].first,u);
                                distancia_vertice[j.second->id] = aux;
                            }

                        }
                    }
                };
            }
        }
        auto x = *distancia_vertice.begin();
        for(auto& i : distancia_vertice){
            if (i.first !=  x.first) {
                auto j = i.second;
                auto size = dist[i.second.first->id];
                if (j.first->id != j.second)
                    size -= dist[j.second];
                dijksstra->createEdge(j.second,j.first->id,size);
            }
        }
    }

    DirectedGraph<TV,TE>* apply(){
        return dijksstra;
    }


};

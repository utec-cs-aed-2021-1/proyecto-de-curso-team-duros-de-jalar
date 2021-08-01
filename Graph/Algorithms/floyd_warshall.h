#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H

#include "../UndirectedGraph.h"
#include "../DirectedGraph.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>


bool check_key(unordered_map<string,int> m, string key){
    return m.find(key) != m.end();
}


template <typename TV, typename TE>
class floyd_warshall{
    DirectedGraph<TV,TE>* floyd;

public:
    floyd_warshall() = default;
    floyd_warshall(Graph<TV,TE>* &grafo){
        floyd = new DirectedGraph<TV,TE>;
        unordered_map<string,unordered_map<string,int>> dist;

        for(auto &i : grafo->vertexes){
            unordered_map<string,int> temp;
            for (auto &o: i.second->edges){
                temp[o->vertexes[1]->id] = o->weight;
            }
            dist[i.first] = temp;
        }

        auto y = grafo;
        for(auto &a :grafo->vertexes){
            auto k = a.first;
            for(auto &b :grafo->vertexes){
                auto  i = b.first;
                for(auto &c :grafo->vertexes){
                    auto j = c.first;
                    auto check_k = check_key(dist[i],k);
                    auto check_i = check_key(dist[i],i);
                    auto check_j = check_key(dist[i],j);

                    if (check_i && check_j && check_k && dist[i][j] > dist[i][k] + dist[k][j]){
                        dist[i][j] =  dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        int cont = 0;
        for(auto &i : dist) {
            floyd->insertVertex(i.first,cont);
            cont++;
        }
        for(auto &i:dist){
            for(auto &j: i.second){
                floyd->createEdge(i.first,j.first,j.second);
            }
        }
    }

    DirectedGraph<TV,TE>* apply(){
        return floyd;
    }
};

#endif //FLOYD_WARSHALL_H

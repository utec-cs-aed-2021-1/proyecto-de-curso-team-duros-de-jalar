#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "..\UndirectedGraph.h"
#include "..\graph.h"
#include "dsarray.h"

template<typename TV, typename TE>
class Kruskal{
private:
    int cost;
    vector<EdgeE<TV, TE>> edges;
    vector<EdgeE<TV, TE>> result;
    UnDirectedGraph<TV, TE>* G;
    Graph<TV,TE>* aux_graph;
public:
    Kruskal()  = default;
    Kruskal(UnDirectedGraph<TV,TE>* &graph){
        aux_graph = graph;
        this->cost = 0;
        n =0;
        for (auto i: graph->vertexes) {
            auto all_edges = i.second->edges;
            for(auto k: all_edges ){
                EdgeE<TV, TE> e;
                e.u = convert(k->vertexes[0]->id);
                e.v = convert(k->vertexes[1]->id);
                e.weight = k->weight;
                edges.push_back(e);
                n++;
            }
        }
        parent.resize(n);
        rankA.resize(n);
        for (int i = 0; i < n; i++)
            MakeSet(i);
    }
    Kruskal(Graph<TV,TE>* &graph){
        aux_graph = graph;
        this->cost = 0;
        n =0;
        for (auto i: graph->vertexes) {
            auto all_edges = i.second->edges;
            for(auto k: all_edges ){
                EdgeE<TV, TE> e;
                e.u = convert(k->vertexes[0]->id);
                e.v = convert(k->vertexes[1]->id);
                e.weight = k->weight;
                edges.push_back(e);
                n++;
            }
        }
        parent.resize(n);
        rankA.resize(n);
        for (int i = 0; i < n; i++)
            MakeSet(i);
    }

    int convert(string id){
        int i = 0;
        for (auto k: aux_graph->vertexes)
        {
            if (k.second->id == id)
                return i;
            i++;
        }
        return i;
    }


    void minimal(){
        sort(edges.begin(), edges.end());
        int k= 0;
        for (EdgeE<TV, TE> e : edges) {
            if (Find(e.u) != Find(e.v)) {
                cost += e.weight;
                result.push_back(e);
                Union(e.u, e.v);
            }
        }
    }

    UnDirectedGraph<TV, TE>* apply(){
        this->minimal();
        G = new UnDirectedGraph<TV, TE>();
        for(pair<string, Vertex<TV, TE> *> vertex: aux_graph->vertexes)
            G->insertVertex(vertex.first, vertex.second->data);
        for (auto edge : result){
            string aux1 , aux2;
            int k =0;
            for(pair<string, Vertex<TV, TE> *> vertex: aux_graph->vertexes){
                if (k == edge.u)
                    aux1 = vertex.first;
                if(k == edge.v)
                    aux2 = vertex.first;
                k++;
            }
            G->createEdge(aux1, aux2, edge.weight);
        }
        return G;
    }

};

#endif

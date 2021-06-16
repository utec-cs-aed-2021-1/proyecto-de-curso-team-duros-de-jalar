#ifndef NONDIRECTEDGRAPH_H
#define NONDIRECTEDGRAPH_H

#include "graph.h"


template<typename TV, typename TE>
class DirectedGraph : public Graph<TV, TE>{
    bool insertVertex(string id, TV vertex) override;
    bool createEdge(string id1, string id2, TE w) override ;
    bool deleteVertex(string id) override;
    bool deleteEdge(string id) override;
    /*
    TE &operator()(string start, string end) override;
    float density() override;
    bool isDense(float threshold = 0.5) override;
    bool isConnected() override;
    bool isStronglyConnected() throw() override;
    bool empty() override;
    void clear() override;

    void displayVertex(string id) override;
    bool findById(string id) override;
    void display() override;
     */
};

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::insertVertex(string id, TV vertex) {
    if(this->vertexes.find(id) != this->vertexes.end())
        return false;

    auto* new_vertex = new Vertex<TV, TE>; new_vertex->data = vertex;
    this->vertexes[id] = new_vertex;

    return true;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::createEdge(string id1, string id2, TE w) {
    if(this->vertexes.find(id1) == this->vertexes.end() && this->vertexes.find(id2) == this->vertexes.end() )
        return false;

    auto* new_edge= new Edge<TV, TE>;
    new_edge->vertexes[0]= this->vertexes[id1];
    new_edge->vertexes[1]= this->vertexes[id2];
    new_edge->weight = w;

    this->vertexes[id1]->edges.push_back(new_edge);

    return true;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::deleteVertex(string id) {
    if(this->vertexes.find(id) == this->vertexes.end())
        return false;
    deleteEdge(id);
    for(auto i = this->vertexes.begin(); i != this->vertexes.end(); i++){ //Revisa cada vértice a excepción del que se va a eliminar
        if((*i).second != this->vertexes[id]){
            auto list_of_edges = (*i).second->edges;

            for(auto j = list_of_edges.begin();  j != list_of_edges.end(); j++){ //Busco si existe una arista que conecte con el vértice id y la borro
                if((*j)->vertexes[1] == this->vertexes[id]){
                    (list_of_edges).erase(j);
                    break;
                }
            }
        }
    }
    this->vertexes.erase(id);
    return true;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::deleteEdge(string id) {
    if(this->vertexes.find(id) == this->vertexes.end())
        return false;

    auto  all_edges =(this->vertexes[id])->edges;

    while(!all_edges.empty()){ // Elimino aristas hasta que la lista de adyacencia quede vacía
        all_edges.pop_front();
    }



    return true;
}

#endif
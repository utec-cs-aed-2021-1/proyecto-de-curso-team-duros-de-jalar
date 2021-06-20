#ifndef NONDIRECTEDGRAPH_H
#define NONDIRECTEDGRAPH_H

#include "graph.h"
#include <iostream>

template<typename TV, typename TE>
class DirectedGraph : public Graph<TV, TE>{
    bool insertVertex(string id, TV vertex) override;
    bool createEdge(string id1, string id2, TE w) override ;
    bool deleteVertex(string id) override;
    bool deleteEdge(string id) override;

    float density() override;
    bool isDense(float threshold = 0.5) override;
    bool isConnected() override;
    bool isStronglyConnected() throw() override;

    /*
    TE &operator()(string start, string end) override;
  */
    bool empty() override;
    void clear() override;

    void displayVertex(string id) override;
    bool findById(string id) override;
    void display() override;

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

template<typename TV,typename TE>
bool DirectedGraph<TV,TE>:: empty(){
    return this->vertexes.size() == 0;
}

template <typename TV,typename TE>
void DirectedGraph<TV,TE>::clear(){
    while (!this->vertexes.empty()){
        auto i = *this->vertexes.begin();
        deleteVertex(i.first);

    }
}

template<typename TV,typename TE>
bool DirectedGraph<TV,TE>::findById(string id) {
    if (this->vertexes.find(id) == this->vertexes.end()) return false;
    return true;
}

template <typename TV,typename TE>
void DirectedGraph<TV,TE>::displayVertex(string id) {
    if(this->vertexes.find(id) == this->vertexes.end())
        return;

    auto  all_edges =(this->vertexes[id])->edges;
    auto ids = id;
    for(auto i: all_edges){
        for (auto it = this->vertexes.begin(); it != this->vertexes.end(); ++it) {
            if (it->second == (*i).vertexes[1]) ids = it->first;
        }

        std::cout<<"weight from vertex " << id << " to vertex " <<  ids << " is " << (*i).weight <<endl;
    }
}
template<typename TV,typename TE>
void DirectedGraph<TV,TE>::display(){
    for(auto i: this->vertexes){
        displayVertex(i.first);
    }
}

template<typename TV, typename TE>
float DirectedGraph<TV, TE>::density() {}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::isDense(float threshold ) {}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::isConnected() {}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::isStronglyConnected() throw() {}

#endif
#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include "graph.h"

template<typename TV, typename TE>
class UnDirectedGraph : public Graph<TV, TE>{
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
bool UnDirectedGraph<TV, TE>::insertVertex(string id, TV vertex) {
    if(this->vertexes.find(id) != this->vertexes.end())
        return false;

    auto* new_vertex = new Vertex<TV, TE>; new_vertex->data = vertex;
    this->vertexes[id] = new_vertex;

    return true;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::createEdge(string id1, string id2, TE w) {
    if(this->vertexes.find(id1) == this->vertexes.end() && this->vertexes.find(id2) == this->vertexes.end() )
        return false;

    auto* new_edge= new Edge<TV, TE>;
    new_edge->vertexes[0]= this->vertexes[id1];
    new_edge->vertexes[1]= this->vertexes[id2];
    new_edge->weight = w;

    this->vertexes[id1]->edges.push_back(new_edge);

    auto* new_edge1= new Edge<TV, TE>;
    new_edge1->vertexes[1]= this->vertexes[id1];
    new_edge1->vertexes[0]= this->vertexes[id2];
    new_edge1->weight = w;


    this->vertexes[id2]->edges.push_back(new_edge1);
    return true;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteVertex(string id) {
    if(this->vertexes.find(id) == this->vertexes.end())
        return false;

    deleteEdge(id);
    this->vertexes.erase(id);

    return true;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteEdge(string id) {
    if(this->vertexes.find(id) == this->vertexes.end())
        return false;

    auto  all_edges =(this->vertexes[id])->edges;

    while(!all_edges.empty()){ //Borrar las aristas de los vértices que conectan con el vértice
        auto get_start_vertex = (*all_edges.begin())->vertexes[0];
        auto get_goal_vertex = (*all_edges.begin())->vertexes[1];

        for(auto i = (get_goal_vertex->edges).begin(); i != (get_goal_vertex->edges).end(); i++){
            if((*i)->vertexes[1] == get_start_vertex){
                (get_goal_vertex->edges).erase(i);
                break;
            }
        }
        all_edges.pop_front();
    }


    return true;
}


#endif
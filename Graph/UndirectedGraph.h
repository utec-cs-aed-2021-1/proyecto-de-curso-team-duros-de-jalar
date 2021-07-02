#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H


#include <iostream>
#include "graph.h"


template<typename TV, typename TE>
class UnDirectedGraph : public Graph<TV, TE> {

public:
    int E = 0;

    bool insertVertex(string id, TV vertex) override;

    bool createEdge(string id1, string id2, TE w) override;

    bool deleteVertex(string id) override;

    bool deleteEdge(string id) override;

    float density() override;

    bool isDense(float threshold = 0.5) override;

    bool isConnected() override;

    bool verify(pair<string, Vertex<TV, TE> *> i, pair<string, Vertex<TV, TE> *> j);

    TE &operator()(string start, string end) override;

    bool empty() override;

    void clear() override;

    void displayVertex(string id) override;

    bool findById(string id) override;

    void display() override;
    
    unordered_map<string, Vertex<TV, TE> *> getVertexes(){

        return this->vertexes;
    }

};

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::insertVertex(string id, TV vertex) {
    if (this->vertexes.find(id) != this->vertexes.end())
        return false;

    auto *new_vertex = new Vertex<TV, TE>;
    new_vertex->data = vertex;
    this->vertexes[id] = new_vertex;

    return true;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::createEdge(string id1, string id2, TE w) {
    if (this->vertexes.find(id1) == this->vertexes.end() && this->vertexes.find(id2) == this->vertexes.end())
        return false;

    auto *new_edge = new Edge<TV, TE>;
    new_edge->vertexes[0] = this->vertexes[id1];
    new_edge->vertexes[1] = this->vertexes[id2];
    new_edge->weight = w;

    this->vertexes[id1]->edges.push_back(new_edge);

    auto *new_edge1 = new Edge<TV, TE>;
    new_edge1->vertexes[1] = this->vertexes[id1];
    new_edge1->vertexes[0] = this->vertexes[id2];
    new_edge1->weight = w;

    this->vertexes[id2]->edges.push_back(new_edge1);
    E++;
    return true;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteVertex(string id) {
    if (this->vertexes.find(id) == this->vertexes.end())
        return false;

    deleteEdge(id);
    this->vertexes.erase(id);

    return true;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteEdge(string id) {
    if (this->vertexes.find(id) == this->vertexes.end())
        return false;

    auto all_edges = (this->vertexes[id])->edges;

    while (!all_edges.empty()) { //Borrar las aristas de los vértices que conectan con el vértice
        auto get_start_vertex = (*all_edges.begin())->vertexes[0];
        auto get_goal_vertex = (*all_edges.begin())->vertexes[1];

        for (auto i = (get_goal_vertex->edges).begin(); i != (get_goal_vertex->edges).end(); i++) {
            if ((*i)->vertexes[1] == get_start_vertex) {
                (get_goal_vertex->edges).erase(i);
                E--;
                break;
            }
        }
        all_edges.pop_front();
    }
    return true;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::empty() {
    return this->vertexes.size() == 0;
}

template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::clear() {
    while (!this->vertexes.empty()) {
        auto i = *this->vertexes.begin();
        deleteVertex(i.first);

    }
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::findById(string id) {
    if (this->vertexes.find(id) == this->vertexes.end()) return false;
    return true;
}

template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::displayVertex(string id) {
    if (this->vertexes.find(id) == this->vertexes.end())
        return;

    auto all_edges = (this->vertexes[id])->edges;
    auto ids = id;
    for (auto i: all_edges) {
        for (auto it = this->vertexes.begin(); it != this->vertexes.end(); ++it) {
            if (it->second == (*i).vertexes[1]) ids = it->first;
        }

        std::cout << "weight from vertex " << id << " to vertex " << ids << " is " << (*i).weight << endl;
    }
}

template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::display() {
    for (auto i: this->vertexes) {
        displayVertex(i.first);
    }
}

template<typename TV, typename TE>
float UnDirectedGraph<TV, TE>::density() {
    int V = this->vertexes.size();
    return 2 * E / ((float) V * (V - 1));

}


template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::isDense(float threshold) {
    return this->density() > threshold;

}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::verify(pair<string, Vertex<TV, TE> *> i, pair<string, Vertex<TV, TE> *> j) {
    auto all_edges = i.second->edges;
    for (auto k : all_edges) {
        if (k->vertexes[0] == j.second || k->vertexes[1] == j.second) {
            return true;
        }
    }
    return false;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::isConnected() {
    int numVertex = this->vertexes.size();
    int matrix[numVertex][numVertex];
    int i = 0;
    for (auto itRows = this->vertexes.begin(); itRows != this->vertexes.end(); ++itRows) {
        int j = 0;
        for (auto itColumn = this->vertexes.begin(); itColumn != this->vertexes.end(); ++itColumn) {
            if (verify(*itRows, *itColumn)) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
            j++;
        }
        i++;
    }

    cout << numVertex << endl;
    for (int i = 0; i < this->vertexes.size(); i++) {
        for (int j = 0; j < this->vertexes.size(); j++) {
            cout << "\t" << matrix[i][j];

        }
        cout << endl;
    }
}

template<typename TV, typename TE>
TE &UnDirectedGraph<TV, TE>::operator()(string start, string end) {
    if (!findById(start))
        throw out_of_range("Vertex not found");
    auto par = this->vertexes[start]->edges;
    for (auto it : par) {
        if (it->vertexes[0] == this->vertexes[end] || it->vertexes[1] == this->vertexes[end]) {
            return it->weight;
        }
    }
    throw std::out_of_range("Edge not found");
}
/*
template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::isStronglyConnected()throw()  {
    throw("Function not supported for undirected graph");
}
*/
#endif

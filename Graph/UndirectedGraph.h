#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H


#include <iostream>
#include <set>
#include "graph.h"
#include <set>
#include <fstream>


template<typename TV, typename TE>
class UnDirectedGraph : public Graph<TV, TE> {

public:
    UnDirectedGraph() = default ;
    UnDirectedGraph(string id, TV vertex) {
        this->insertVertex(id,vertex);
    }

    int E = 0;

    bool insertVertex(string id, TV vertex) override;

    bool createEdge(string id1, string id2, TE w) override;

    bool deleteVertex(string id) override;

    bool deleteEdge(string start, string end) override;

    bool deleteEdges(string id) override;

    float density() override;

    bool isDense(float threshold = 0.5) override;

    bool isConnected() override;

    TE &operator()(string start, string end) override;

    bool empty() override;

    void clear() override;

    void displayVertex(string id) override{};

    bool findById(string id) override;

    void display() override;

    TV operator[](string id);

    unordered_map<string, Vertex<TV, TE> *> getVertexes(){
        return this->vertexes;
    }

    void display_file(ofstream &filename);

    bool isStronglyConnected() throw();

        ~UnDirectedGraph();


};


template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::insertVertex(string id, TV vertex) {
    if (this->vertexes.find(id) != this->vertexes.end())
        return false;

    auto *new_vertex = new Vertex<TV, TE>;
    new_vertex->data = vertex;
    new_vertex->id = id;
    this->vertexes[id] = new_vertex;

    return true;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::createEdge(string id1, string id2, TE w) {
    if (this->vertexes.find(id1) == this->vertexes.end() || this->vertexes.find(id2) == this->vertexes.end())
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

    deleteEdges(id);
    this->vertexes.erase(id);

    return true;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteEdges(string id) {
    if (this->vertexes.find(id) == this->vertexes.end())
        return false;

    auto all_edges = &(this->vertexes[id])->edges;

    while (!all_edges->empty()) {
        auto get_start_vertex = (*all_edges->begin())->vertexes[0];
        auto get_goal_vertex = (*all_edges->begin())->vertexes[1];

        for (auto i = (get_goal_vertex->edges).begin(); i != (get_goal_vertex->edges).end(); i++) {
            if ((*i)->vertexes[1] == get_start_vertex) {
                (get_goal_vertex->edges).erase(i);
                E--;
                break;
            }
        }
        all_edges->pop_front();
    }
    return true;
}


template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteEdge(string start, string end){
    if (this->vertexes.find(start) == this->vertexes.end() && this->vertexes.find(end) == this->vertexes.end())
        return false;

    auto all_edges = &(this->vertexes[start])->edges;
    for (auto i = all_edges->begin(); i != all_edges->end(); i++) {
        if (((*i)->vertexes[1])->id == end) {
            all_edges->erase(i);
        }
    }

    auto all_edges1 = &(this->vertexes[end])->edges;
    for (auto i = all_edges1->begin(); i != all_edges1->end(); i++) {
        if (((*i)->vertexes[1])->id == start) {
            all_edges1->erase(i);
        }
    }
    E--;
    return true;
}

template<typename TV, typename TE>
TV UnDirectedGraph<TV, TE>::operator[](string id) {
    if (this->vertexes.find(id) != this->vertexes.end())
        return this->vertexes[id]->data;
    else
        return TV();
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
/*
template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::displayVertex(string id){
    if (this->vertexes.find(id) == this->vertexes.end())
        return;
    auto data = this->vertexes[id];
    auto all_edges = (this->vertexes[id])->edges;
    auto ids = id;
    cout<<"connections to vertex "<< data->id << " with data " << data->data<<endl;
    for (auto i: all_edges) {
        for (auto it = this->vertexes.begin(); it != this->vertexes.end(); ++it) {
            if (it->second == (*i).vertexes[1]) ids = it->first;
        }

        std::cout << " to vertex " << ids << " the weight is " << (*i).weight << endl;
    }
}

*/

template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::display() {
    vector<pair<string, string>> visited;
    for (auto i: this->vertexes) {
        string id = i.first;

        auto all_edges = (this->vertexes[id])->edges;
        for (auto j: all_edges) {
            string ids = (j->vertexes[1])->id;
            bool was_visited = true;
            for(const auto & k : visited){
                if((k.first == id && k.second ==ids) || (k.first == ids && k.second ==id)){
                    was_visited = false;
                    break;
                }
            }
            if(was_visited) {
                visited.push_back(make_pair(id,ids));
                std::cout << "weight from vertex " << id << " to vertex " << ids << " is " << (*j).weight << endl;
            }
        }
    }
}

template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::display_file(ofstream &filename) {
    filename <<"graph graph1{ "<<endl;
    vector<pair<string, string>> visited;
    for (auto i: this->vertexes) {
        string id = i.first;

        auto all_edges = (this->vertexes[id])->edges;
        for (auto j: all_edges) {
            string ids = (j->vertexes[1])->id;
            bool was_visited = true;
            for(const auto & i : visited){
                if((i.first == id && i.second ==ids) || (i.first == ids && i.second ==id)){
                    was_visited = false;
                    break;
                }
            }
            if(was_visited) {
                visited.push_back(make_pair(id,ids));
                filename << id <<" -- "<< ids << " [label = \""<< (*j).weight<<"\"];"<<endl;
            }
        }
    }
    filename <<" } ";

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

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::isConnected() {
    std::set<string> visited;
    std::stack<Vertex<TV, TE>* > pila;

    string fid = (*this->vertexes.begin()).first;
    visited.insert(fid);

    for (auto i : (*this->vertexes.begin()).second->edges) {
        Vertex<TV, TE> *ax = i->vertexes[1];
        if (visited.find(ax->id) == visited.end()) {
            pila.push(ax);
        }
    }

    while (!pila.empty()) {
        Vertex<TV, TE> *to_insert = pila.top();
        pila.pop();
        visited.insert(to_insert->id);

        for (auto i : to_insert->edges) {
            Vertex<TV, TE> *ax = i->vertexes[1];
            if (visited.find(ax->id) == visited.end()) {
                pila.push(ax);
            }
        }
    }
    if (visited.size() == this->vertexes.size()){return true;}
    return false;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::isStronglyConnected()throw()  {
    if(this->isConnected()){return true;}
    else{return false;}
}

template<typename TV, typename TE>
UnDirectedGraph<TV, TE>::~UnDirectedGraph() {
    while(this->vertexes.size()){
        deleteVertex((*this->vertexes.begin()).first);
    }
}


#endif

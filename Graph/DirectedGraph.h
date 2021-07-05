#ifndef NONDIRECTEDGRAPH_H
#define NONDIRECTEDGRAPH_H

#include <set>
#include "graph.h"
#include <iostream>


template<typename TV, typename TE>
class DirectedGraph : public Graph<TV, TE> {
public:
    DirectedGraph() = default;
    DirectedGraph(string id, TV vertex) {
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

    bool isStronglyConnected() throw() ;

    TE &operator()(string start, string end) override;

    bool empty() override;

    void clear() override;

    void displayVertex(string id) override;

    void displayVertexFile(ofstream &filename, string id) ;

    void display_file(ofstream &filename);

    bool findById(string id) override;

    void display() override;

    ~DirectedGraph();


};

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::insertVertex(string id, TV vertex) {
    if (this->vertexes.find(id) != this->vertexes.end())
        return false;

    auto *new_vertex = new Vertex<TV, TE>;
    new_vertex->data = vertex;
    new_vertex->id = id;
    this->vertexes[id] = new_vertex;

    return true;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::createEdge(string id1, string id2, TE w) {
    if (this->vertexes.find(id1) == this->vertexes.end() && this->vertexes.find(id2) == this->vertexes.end())
        return false;

    auto *new_edge = new Edge<TV, TE>;
    new_edge->vertexes[0] = this->vertexes[id1];
    new_edge->vertexes[1] = this->vertexes[id2];
    new_edge->weight = w;

    this->vertexes[id1]->edges.push_back(new_edge);
    E++;
    return true;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::deleteVertex(string id) {
    if (this->vertexes.find(id) == this->vertexes.end())
        return false;
    deleteEdges(id);
    for (auto i = this->vertexes.begin(); i != this->vertexes.end(); i++) { //Revisa cada vértice a excepción del que se va a eliminar
        if ((*i).second != this->vertexes[id]) {
            auto list_of_edges = (*i).second->edges;

            for (auto j = list_of_edges.begin(); j != list_of_edges.end(); j++) { //Busco si existe una arista que conecte con el vértice id y la borro
                if ((*j)->vertexes[1] == this->vertexes[id]) {
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
bool DirectedGraph<TV, TE>::deleteEdges(string id) {
    if (this->vertexes.find(id) == this->vertexes.end())
        return false;

    auto all_edges = &(this->vertexes[id])->edges;

    while (!all_edges->empty()) { // Elimino aristas hasta que la lista de adyacencia quede vacía
        E--;
        all_edges->pop_front();
    }

    return true;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::deleteEdge(string start, string end) {
    if (this->vertexes.find(start) == this->vertexes.end() && this->vertexes.find(end) == this->vertexes.end())
        return false;

    auto all_edges = &(this->vertexes[start])->edges;
    for(auto i = all_edges->begin(); i!=all_edges->end(); i++){
        if(((*i)->vertexes[1])->id == end){
            all_edges->erase(i);
            return true;
        }
    }
    E--;

    return false;
}


template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::empty() {
    return this->vertexes.size() == 0;
}

template<typename TV, typename TE>
void DirectedGraph<TV, TE>::clear() {
    while (!this->vertexes.empty()) {
        auto i = *this->vertexes.begin();
        deleteVertex(i.first);

    }
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::findById(string id) {
    if (this->vertexes.find(id) == this->vertexes.end()) return false;
    return true;
}

template<typename TV, typename TE>
void DirectedGraph<TV, TE>::displayVertex(string id) {
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

template<typename TV, typename TE>
void DirectedGraph<TV, TE>::displayVertexFile(ofstream &filename, string id) {
    if (this->vertexes.find(id) == this->vertexes.end())
        return;

    auto all_edges = (this->vertexes[id])->edges;
    auto ids = id;
    for (auto i: all_edges) {
        for (auto it = this->vertexes.begin(); it != this->vertexes.end(); ++it) {
            if (it->second == (*i).vertexes[1]) ids = it->first;
        }

        filename << id <<" -> "<< ids << " [label = \""<< (*i).weight<<"\"];"<<endl;
    }
}


template<typename TV, typename TE>
void DirectedGraph<TV, TE>::display_file(ofstream &filename){

    filename <<"digraph graph1{ "<<endl;
    for (auto i: this->vertexes) {
        displayVertexFile(filename, i.first);
    }
    filename <<" } ";
}

template<typename TV, typename TE>
void DirectedGraph<TV, TE>::display() {
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
                std::cout << "weight from vertex " << id << " to vertex " << ids << " is " << (*j).weight << endl;
            }
        }
    }
}

template<typename TV, typename TE>
float DirectedGraph<TV, TE>::density() {
    int V = this->vertexes.size();
    return 2 * E / ((float) V * (V - 1));
}


template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::isDense(float threshold) {
    return this->density() > threshold;
}


template<typename TV, typename TE>
TE &DirectedGraph<TV, TE>::operator()(string start, string end) {
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
bool DirectedGraph<TV, TE>::isStronglyConnected() throw() {
    for(auto &j : this->vertexes){
        std::unordered_set<string> visited;
        std::stack<Vertex<TV, TE> *> pila;

        visited.insert(j.first);

        for (auto i : j.second->edges) {
            Vertex<TV, TE> *ax = i->vertexes[1];
            if (visited.find(ax->id) == visited.end()) {
                pila.push(ax);
            }
        }


        while (!pila.empty()) {
            Vertex<TV, TE> * to_insert = pila.top();
            pila.pop();
            visited.insert(to_insert->id);

            for (auto i : to_insert->edges) {
                Vertex<TV, TE> *ax = i->vertexes[1];
                if (visited.find(ax->id) == visited.end()) {
                    pila.push(ax);
                }
            }
        }
        if (visited.size() != this->vertexes.size()){return false;}
    }
    return true;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::isConnected() {
    for(auto &j : this->vertexes){
        std::unordered_set<string> visited;
        std::stack<Vertex<TV, TE> *> pila;

        visited.insert(j.first);

        for (auto i : j.second->edges) {
            Vertex<TV, TE> *ax = i->vertexes[1];
            if (visited.find(ax->id) == visited.end()) {
                pila.push(ax);
            }
        }

        while (!pila.empty()) {
            Vertex<TV, TE> * to_insert = pila.top();
            pila.pop();
            visited.insert(to_insert->id);

            for (auto i : to_insert->edges) {
                Vertex<TV, TE> *ax = i->vertexes[1];
                if (visited.find(ax->id) == visited.end()) {
                    pila.push(ax);
                }
            }
        }
        if (visited.size() == this->vertexes.size()){return  true;}
    }
    return false;
}

template<typename TV, typename TE>
DirectedGraph<TV, TE>::~DirectedGraph() {
    while(this->vertexes.size()){
        deleteVertex((*this->vertexes.begin()).first);
    }
}


#endif

#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <unordered_map>
#include <functional>
#include<queue>
#include <stack>
#include<unordered_set>

using namespace std;

template<typename TV, typename TE>
struct Edge;

template<typename TV, typename TE>
struct Vertex;

template<typename TV, typename TE>
class Graph;

//////////////////////////////////////////////////////

template<typename TV, typename TE>
struct Edge {
    Vertex<TV, TE> *vertexes[2];
    TE weight;
};

template<typename TV, typename TE>
struct Vertex {
    string id;
    TV data;
    std::list<Edge<TV, TE> *> edges;
};

template<typename TV, typename TE>
class Graph {
protected:

public:
    std::unordered_map<string, Vertex<TV, TE> *> vertexes;

    Graph() = default;

    virtual bool insertVertex(string id, TV vertex) = 0;

    virtual bool createEdge(string id1, string id2, TE w) = 0;

    virtual bool deleteVertex(string id) = 0;

    virtual bool deleteEdges(string id) = 0;

    virtual bool deleteEdge(string start, string end) = 0;

    virtual bool isDense(float threshold = 0.5) = 0;

    virtual float density() = 0;

    virtual bool isConnected() = 0;

    virtual TE &operator()(string start, string end) = 0;

    virtual bool empty() = 0;

    virtual void clear() = 0;

    virtual void displayVertex(string id) = 0;

    virtual bool findById(string id) = 0;

    virtual bool isStronglyConnected() throw() = 0;

    virtual void display() = 0;

    virtual void display_file(ofstream &filename) = 0;

    ~Graph() = default;

};




#endif

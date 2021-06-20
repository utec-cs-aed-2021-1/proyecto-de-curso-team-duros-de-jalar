#include <iostream>
#include "UndirectedGraph.h"
#include "DirectedGraph.h"
#include "graph.h"

using namespace std;

int main() {
/*
    UnDirectedGraph<int, float> graph;

    graph.insertVertex("A", 1);
    graph.insertVertex("B", 2);
    graph.insertVertex("C", 3);
    graph.insertVertex("D", 4);

    graph.createEdge("A", "B", 9);
    graph.createEdge("A", "C", 3);
    graph.createEdge("A", "D", 8);
    graph.createEdge("B", "C", 10);


    cout << graph.density() << endl;
    graph.display();
    graph.isConnected();
    cout << "weight " << graph("A", "B") << endl;
    graph.deleteVertex("B");
*/

    DirectedGraph<int, float> graph;

    graph.insertVertex("A", 1);
    graph.insertVertex("B", 2);
    graph.insertVertex("C", 3);
    graph.insertVertex("D", 4);

    graph.createEdge("A", "B", 9);
    graph.createEdge("A", "C", 3);
    graph.createEdge("A", "D", 8);
    graph.createEdge("B", "C", 10);
    graph.createEdge("C", "B", 10);


    cout << graph.density() << endl;
    graph.display();
    graph.isConnected();
    //cout << "weight " << graph("A", "B") << endl;
    graph.deleteVertex("B");
    return 0;
}
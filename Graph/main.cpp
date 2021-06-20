#include <iostream>
#include "UndirectedGraph.h"
#include "graph.h"
using namespace std;

int main(){

    UnDirectedGraph<int, float> graph;

    graph.insertVertex("A", 1);
    graph.insertVertex("B", 2);
    graph.insertVertex("C", 3);
    graph.insertVertex("D", 4);

    graph.createEdge("A", "B", 9 );
    graph.createEdge("A", "C", 3 );
    graph.createEdge("A", "D", 8 );
    graph.createEdge("B", "C", 10 );

    graph.deleteVertex("B");

    cout<<graph.density()<<endl;

    graph.display();

    return 0;
}
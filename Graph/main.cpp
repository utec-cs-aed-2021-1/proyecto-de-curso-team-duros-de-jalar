#include <iostream>
#include "UndirectedGraph.h"
#include "DirectedGraph.h"
#include "graph.h"
#include "Algorithms\kruskal.h"
#include "Algorithms\dfs.h"
#include "Algorithms\bfs.h"

using namespace std;
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    UnDirectedGraph<int, float> graph;

    graph.insertVertex("A", 1);
    graph.insertVertex("B", 2);
    graph.insertVertex("C", 3);
    graph.insertVertex("D", 4);

    graph.createEdge("A", "B", 9);
    graph.createEdge("B", "A", 9);
    graph.createEdge("C", "A", 3);
    graph.createEdge("A", "C", 3);
    graph.createEdge("A", "D", 8);
    graph.createEdge("D", "A", 8);
    graph.createEdge("B", "C", 10);
    graph.createEdge("C", "B", 10);


    /* Graph<int, float>* graph = new UnDirectedGraph<int,float>;

     graph->insertVertex("A", 1);
     graph->insertVertex("B", 2);
     graph->insertVertex("C", 3);
     graph->insertVertex("D", 4);

     graph->createEdge("A", "B", 9);
     graph->createEdge("B", "A", 9);
     graph->createEdge("C", "A", 3);
     graph->createEdge("A", "C", 3);
     graph->createEdge("A", "D", 8);
     graph->createEdge("D", "A", 8);
     graph->createEdge("B", "C", 10);
     graph->createEdge("C", "B", 10);*/
/*    dfs<int,float> dfs (graph, "A");

    cout << graph->density() << endl;
    dfs.apply()->display();

    DirectedGraph<int, float>* result = dfs.apply();
*/


    Kruskal<int, float> kruskal(&graph);
    UnDirectedGraph<int, float> result = kruskal.apply();//return a tree
    result.display();
    ofstream MyFile;
    MyFile.open("hola.dot");
    result.display_file(MyFile);
    // Close the file
    MyFile.close();

    // Create and open a text file


    return 0;
}

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

    cout << "weight " << graph("A", "B") << endl;
    cout << "weight " << graph("B", "C") << endl;

    if ( graph.isConnected())
        cout<<"is connected"<<endl;
    else
        cout<<"is not connected"<<endl;



    cout << graph.density() << endl;
    graph.display();
    if ( graph.isConnected())
        cout<<"is connected"<<endl;

    cout << "weight " << graph("A", "B") << endl;
    graph.deleteVertex("B");


    DirectedGraph<int, float> graph;

    graph.insertVertex("A", 1);
    graph.insertVertex("B", 2);
    graph.insertVertex("C", 3);
    graph.insertVertex("D", 4);

    graph.createEdge("A", "B", 10);
    graph.createEdge("B", "A", 1);
    graph.createEdge("B", "C", 12);
    graph.createEdge("C", "A", 6);

    graph.createEdge("A", "C", 3);
    graph.createEdge("A", "D", 8);
    graph.createEdge("B", "C", 10);
    graph.createEdge("C", "B", 10);
    graph.createEdge("C", "D", 4);


    cout << graph.density() << endl;
    graph.display();
    if ( graph.isStronglyConnected())
        cout<<"is connected"<<endl;
    else
        cout<<"is not connected"<<endl;
    cout << "weight " << graph("A", "B") << endl;
    cout << "weight " << graph("B", "A") << endl;
    //graph.deleteVertex("B");
    */
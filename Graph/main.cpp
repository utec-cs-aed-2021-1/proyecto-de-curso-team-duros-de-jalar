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


    DirectedGraph<int, float> graph;
    /*Undirected graph */

    /*GRAPH 1*/
/*
    graph.insertVertex("A", 1);
    graph.insertVertex("B", 2);
    graph.insertVertex("C", 3);
    graph.insertVertex("D", 4);
    graph.insertVertex("E", 5);
    graph.insertVertex("F", 6);
    graph.insertVertex("G", 7);
    graph.insertVertex("H", 8);
    graph.insertVertex("I", 9);
    graph.insertVertex("J", 10);
    graph.insertVertex("K", 11);
    graph.insertVertex("L", 12);
    graph.insertVertex("M", 13);
    graph.insertVertex("N", 14);
    graph.insertVertex("O", 15);

    graph.createEdge("A", "B", 9);
    graph.createEdge("A", "C", 2);

    graph.createEdge("B", "D", 1);

    graph.createEdge("C", "D", 3);

    graph.createEdge("D", "E", 8);
    graph.createEdge("D", "F", 5);

    graph.createEdge("E", "A", 4);

    graph.createEdge("F", "A", 7);
    graph.createEdge("F", "J", 0);

    graph.createEdge("G", "F", 6);
    graph.createEdge("G", "H", 10);
    graph.createEdge("G", "I", 1);

    graph.createEdge("H", "G", 1);
    graph.createEdge("H", "I", 4);
    graph.createEdge("H", "O", 12);

    graph.createEdge("I", "H", 15);
    graph.createEdge("I", "G", 6);

    graph.createEdge("J", "K", 11);
    graph.createEdge("J", "L", 7);
    graph.createEdge("J", "M", 3);

    graph.createEdge("K", "J", 18);
    graph.createEdge("K", "L", 2);

    graph.createEdge("L", "J", 14);
    graph.createEdge("L", "K", 19);
    graph.createEdge("L", "N", 1);

    graph.createEdge("M", "G", 7);

    graph.createEdge("N", "I", 6);

    graph.createEdge("O", "L", 8);
*/


    /*GRAPH 2*/
/*  graph.insertVertex("A", 1);
    graph.insertVertex("B", 2);
    graph.insertVertex("C", 3);
    graph.insertVertex("D", 4);
    graph.insertVertex("E", 5);
    graph.insertVertex("F", 6);
    graph.insertVertex("G", 7);
    graph.insertVertex("H", 8);
    graph.insertVertex("I", 9);
    graph.insertVertex("J", 10);
    graph.insertVertex("K", 11);
    graph.insertVertex("L", 12);
    graph.insertVertex("M", 13);
    graph.insertVertex("N", 14);
    graph.insertVertex("O", 15);
    graph.insertVertex("P", 16);
    graph.insertVertex("Q", 17);
    graph.insertVertex("R", 18);

    graph.createEdge("A", "D", 19);
    graph.createEdge("A", "C", 12);

    graph.createEdge("B", "D", 11);
    graph.createEdge("B", "A", 17);

    graph.createEdge("C", "A", 13);
    graph.createEdge("C", "B", 14);
    graph.createEdge("C", "M", 10);

    graph.createEdge("D", "B", 18);
    graph.createEdge("D", "C", 15);
    graph.createEdge("D", "E", 22);

    graph.createEdge("E", "F", 21);
    graph.createEdge("E", "G", 29);
    graph.createEdge("E", "M", 14);

    graph.createEdge("F", "C", 17);
    graph.createEdge("F", "E", 12);
    graph.createEdge("F", "G", 25);
    graph.createEdge("F", "K", 19);

    graph.createEdge("G", "E", 16);
    graph.createEdge("G", "I", 24);
    graph.createEdge("G", "F", 10);
    graph.createEdge("G", "Q", 11);
    graph.createEdge("G", "R", 23);

    graph.createEdge("H", "I", 21);
    graph.createEdge("H", "K", 14);

    graph.createEdge("I", "J", 15);

    graph.createEdge("J", "H", 21);
    graph.createEdge("J", "L", 17);
    graph.createEdge("J", "P", 13);

    graph.createEdge("K", "L", 28);
    graph.createEdge("K", "M", 12);

    graph.createEdge("L", "K", 19);
    graph.createEdge("L", "N", 21);

    graph.createEdge("M", "K", 11);
    graph.createEdge("M", "N", 27);
    graph.createEdge("M", "O", 16);

    graph.createEdge("N", "L", 20);
    graph.createEdge("N", "M", 17);

    graph.createEdge("O", "N", 30);

    graph.createEdge("P", "I", 32);

    graph.createEdge("Q", "G", 31);
    graph.createEdge("Q", "R", 13);

    graph.createEdge("R", "G", 10);
    graph.createEdge("R", "Q", 35);
*/


/*GRAPH 3*/
/*    graph.insertVertex("A", 1);
    graph.insertVertex("B", 2);
    graph.insertVertex("C", 3);
    graph.insertVertex("D", 4);
    graph.insertVertex("E", 5);
    graph.insertVertex("F", 6);
    graph.insertVertex("G", 7);
    graph.insertVertex("H", 8);
    graph.insertVertex("I", 9);
    graph.insertVertex("J", 10);
    graph.insertVertex("K", 11);
    graph.insertVertex("L", 12);
    graph.insertVertex("M", 13);
    graph.insertVertex("N", 14);
    graph.insertVertex("O", 15);
    graph.insertVertex("P", 16);
    graph.insertVertex("Q", 17);
    graph.insertVertex("R", 18);

   graph.createEdge("B", "A", 80);

   graph.createEdge("C", "D", 13);

   graph.createEdge("D", "C", 45);

   graph.createEdge("E", "A", 21);
   graph.createEdge("E", "H", 69);

   graph.createEdge("F", "G", 17);
   graph.createEdge("F", "I", 52);

   graph.createEdge("G", "D", 89);

   graph.createEdge("H", "I", 71);
   graph.createEdge("H", "L", 34);

   graph.createEdge("I", "J", 15);

   graph.createEdge("J", "H", 21);
   graph.createEdge("J", "L", 17);
   graph.createEdge("J", "P", 13);

   graph.createEdge("K", "D", 28);
   graph.createEdge("K", "R", 27);

   graph.createEdge("L", "H", 19);
   graph.createEdge("L", "I", 21);
   graph.createEdge("L", "P", 21);

   graph.createEdge("M", "J", 11);
   graph.createEdge("M", "N", 27);

   graph.createEdge("N", "K", 20);

   graph.createEdge("O", "P", 30);

   graph.createEdge("Q", "P", 62);
*/

    // Create and open a text file
    ofstream MyFile;
    MyFile.open("graph1.dot");
    graph.display_file(MyFile);
    // Close the file
    MyFile.close();


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



    Kruskal<int, float> kruskal(&graph);
    UnDirectedGraph<int, float> result = kruskal.apply();//return a tree
    result.display();*/

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
#include <iostream>

#include "Tester/tester.h"
#include "Parser/parse.h"

using namespace std;

int main() {
    std::cout << "================================================" << std::endl;
    std::cout << "MENU GRAPH TESTER" << std::endl;
    std::cout << "================================================" << std::endl;

    Tester::executeExamples();
    //Tester::executeParser();
    //Tester::executeParser(file::airports);
    /*   Parser parser;
       parser.generateJson(file::pe);

       UnDirectedGraph<Airport, double> *unDirectedGraph = new  UnDirectedGraph<Airport, double>;
       //DirectedGraph<Airport, double> DirectedGraph;
      parser.generateUndirectedGraph(unDirectedGraph);
       unDirectedGraph->display();
       //parser.generateDirectedGra(DirectedGraph);
     /*   Graph<Airport, double> *graph = new UnDirectedGraph<Airport, double>;
       cout << "Kruskal" << endl;
       Kruskal<Airport, double> kruskal(graph);
       UnDirectedGraph<Airport, double> *result = kruskal.apply();//return a tree
       result->display();
   */

    /*
    ofstream MyFile;
    MyFile.open("airportsUndirected.dot");
    UnDirectedGraph.display_file(MyFile);
    MyFile.close();*/
    return EXIT_SUCCESS;
}
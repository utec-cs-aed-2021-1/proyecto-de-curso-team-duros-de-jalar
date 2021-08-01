#include <iostream>

#include "Tester/tester.h"
#include "Parser/parse.h"

using namespace std;

int main() {
    std::cout << "================================================" << std::endl;
    std::cout << "MENU GRAPH TESTER" << std::endl;
    std::cout << "================================================" << std::endl;

    //Tester::executeExamples();
    //Tester::executeParser();
    //Tester::executeParser(file::airports);
    Parser parser;
    parser.generateJson(file::airports);

    UnDirectedGraph<Airport, double> UnDirectedGraph;
    DirectedGraph<Airport, double> DirectedGraph;
    parser.generateUndirectedGraph(UnDirectedGraph);
    //parser.generateDirectedGraph(DirectedGraph);
    //
    ofstream MyFile;
    MyFile.open("airportsUndirected.dot");
    UnDirectedGraph.display_file(MyFile);
    // Close the file
    MyFile.close();
    return EXIT_SUCCESS;
}
#include <iostream>

#include "Tester/tester.h"
#include "Parser/parse.h"

using namespace std;

int main(int argc, char *argv[]) {
    std::cout << "================================================" << std::endl;
    std::cout << "MENU GRAPH TESTER" << std::endl;
    std::cout << "================================================" << std::endl;

    //Tester::executeExamples();
    //Tester::executeParser();
    //Tester::executeParser(file::airports);
    Parser parser;
    parser.generateJson(file::pe);

    UnDirectedGraph<Airport, double> UnDirectedGraph;
    DirectedGraph<Airport, double> DirectedGraph;
    parser.generateUndirectedGraph(UnDirectedGraph);

    return EXIT_SUCCESS;
}
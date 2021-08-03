#include <iostream>

#include "Tester/tester.h"
#include "Parser/parse.h"

using namespace std;

int main() {
    std::cout << "================================================" << std::endl;
    std::cout << "MENU GRAPH TESTER" << std::endl;
    std::cout << "================================================" << std::endl;

    Tester::executeExamples();

    return EXIT_SUCCESS;
}
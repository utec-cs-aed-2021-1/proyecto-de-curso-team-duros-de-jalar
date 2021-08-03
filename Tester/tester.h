#ifndef TESTER_H
#define TESTER_H

#include <iostream>
#include <cstdlib>
#include "../Graph/UndirectedGraph.h"
#include "../Graph/directedGraph.h"
#include "../Graph/Algorithms/prim.h"
#include "../Graph/Algorithms/kruskal.h"
#include "../Graph/Algorithms/bfs.h"
#include "../Graph/Algorithms/dfs.h"
#include "../Graph/Algorithms/dijkstra.h"
#include "../Parser/parse.h"
#include "../Graph/Algorithms/astar.h"
#include <fstream>
#include <Algorithms/bellman.h>
#include <Algorithms/floyd_warshall.h>

using namespace std;
namespace Tester {
    int input_Case{};
    int metodo{};
    static void executeParser(file json_file );

    void GDirigido() {
        cout << "Seleccione el grafo (1 al 3) que desee: ";
        int a;
        cin >> a;
        switch (a) {
            case 1: {
                executeParser(file::pe);
                Graph<int, float> *graph = new DirectedGraph<int, float>;
                DirectedGraph<Airport, double> DirectedGraph;

                graph->insertVertex("A", 1);
                graph->insertVertex("B", 2);
                graph->insertVertex("C", 3);
                graph->insertVertex("D", 4);
                graph->insertVertex("E", 5);
                graph->insertVertex("F", 6);
                graph->insertVertex("G", 7);
                graph->insertVertex("H", 8);
                graph->insertVertex("I", 9);
                graph->insertVertex("J", 10);
                graph->insertVertex("K", 11);
                graph->insertVertex("L", 12);
                graph->insertVertex("M", 13);
                graph->insertVertex("N", 14);
                graph->insertVertex("O", 15);

                graph->createEdge("A", "B", 9);
                graph->createEdge("A", "C", 2);

                graph->createEdge("B", "D", 1);

                graph->createEdge("C", "D", 3);

                graph->createEdge("D", "E", 8);
                graph->createEdge("D", "F", 5);

                graph->createEdge("E", "A", 4);

                graph->createEdge("F", "A", 7);
                graph->createEdge("F", "J", 0);

                graph->createEdge("G", "F", 6);
                graph->createEdge("G", "H", 10);
                graph->createEdge("G", "I", 1);

                graph->createEdge("H", "G", 1);
                graph->createEdge("H", "I", 4);
                graph->createEdge("H", "O", 12);

                graph->createEdge("I", "H", 15);
                graph->createEdge("I", "G", 6);

                graph->createEdge("J", "K", 11);
                graph->createEdge("J", "L", 7);
                graph->createEdge("J", "M", 3);

                graph->createEdge("K", "J", 18);
                graph->createEdge("K", "L", 2);

                graph->createEdge("L", "J", 14);
                graph->createEdge("L", "K", 19);
                graph->createEdge("L", "N", 1);

                graph->createEdge("M", "G", 7);

                graph->createEdge("N", "I", 6);

                graph->createEdge("O", "L", 8);

                // Create and open a text file
                ofstream MyFile;
                MyFile.open("graph1.dot");
                graph->display_file(MyFile);
                // Close the file
                MyFile.close();

                do {
                    cout << "\n\n Elija el metodo " << endl;
                    cout << "1. Mostrar grafo" << endl;
                    cout << "2. Densidad del grafo" << endl;
                    cout << "3. Es conexo" << endl;
                    cout << "4. Es fuertemente conexo" << endl;
                    cout << "5. BFS" << endl;
                    cout << "6. DFS" << endl;
                    cout<<"Para salir del bucle insertar cualquier numero"<<endl;

                    cin >> metodo;

                    switch (metodo) {
                        case 1: {
                            graph->display();
                            break;
                        }
                        case 2: {
                            if (graph->isDense()) {
                                cout << "Es un grado denso" << endl;
                                cout << "Su densidad es " << graph->density() << endl;
                            } else {
                                cout << "No es un grafo denso" << endl;
                                cout << "Su densidad es " << graph->density() << endl;
                            }
                            break;
                        }
                        case 3: {
                            if (graph->isConnected()) { cout << "Es un grafo conexo" << endl; }
                            else { cout << "No es un grafo conexo" << endl; }
                            break;
                        }
                        case 4: {
                            if (graph->isStronglyConnected()) { cout << "Es un fuertemente grafo conexo" << endl; }
                            else { cout << "No es un grafo fuertemente conexo" << endl; }
                            break;
                        }
                        case 5: {
                            cout << "BFS desde el vertice A" << endl;
                            bfs<int, float> bfs_(graph, "A");
                            bfs_.apply()->display();

                            break;
                        }
                        case 6: {
                            cout << "DFS desde el vertice A" << endl;
                            dfs<int, float> dfs_(graph, "A");
                            dfs_.apply()->display();
                            break;
                        }
                    }
                }while (metodo <= 6 && 1 <= metodo);


                break;
            }
            case 2: {
                Graph<int, float> *graph1 = new DirectedGraph<int, float>;

                graph1->insertVertex("A", 1);
                graph1->insertVertex("B", 2);
                graph1->insertVertex("C", 3);
                graph1->insertVertex("D", 4);
                graph1->insertVertex("E", 5);
                graph1->insertVertex("F", 6);
                graph1->insertVertex("G", 7);
                graph1->insertVertex("H", 8);
                graph1->insertVertex("I", 9);
                graph1->insertVertex("J", 10);
                graph1->insertVertex("K", 11);
                graph1->insertVertex("L", 12);
                graph1->insertVertex("M", 13);
                graph1->insertVertex("N", 14);
                graph1->insertVertex("O", 15);
                graph1->insertVertex("P", 16);
                graph1->insertVertex("Q", 17);
                graph1->insertVertex("R", 18);

                graph1->createEdge("B", "A", 80);

                graph1->createEdge("C", "D", 13);

                graph1->createEdge("D", "C", 45);

                graph1->createEdge("E", "A", 21);
                graph1->createEdge("E", "H", 69);

                graph1->createEdge("F", "G", 17);
                graph1->createEdge("F", "I", 52);

                graph1->createEdge("G", "D", 89);

                graph1->createEdge("H", "I", 71);
                graph1->createEdge("H", "L", 34);

                graph1->createEdge("I", "J", 15);

                graph1->createEdge("J", "H", 21);
                graph1->createEdge("J", "L", 17);
                graph1->createEdge("J", "P", 13);

                graph1->createEdge("K", "D", 28);
                graph1->createEdge("K", "R", 27);

                graph1->createEdge("L", "H", 19);
                graph1->createEdge("L", "I", 21);
                graph1->createEdge("L", "P", 21);

                graph1->createEdge("M", "J", 11);
                graph1->createEdge("M", "N", 27);

                graph1->createEdge("N", "K", 20);

                graph1->createEdge("O", "P", 30);

                graph1->createEdge("Q", "P", 62);

                // Create and open a text file
                ofstream MyFile;
                MyFile.open("graph2.dot");
                graph1->display_file(MyFile);
                // Close the file
                MyFile.close();

                do {
                    cout << "\n\n Elija el metodo " << endl;
                    cout << "1. Mostrar grafo" << endl;
                    cout << "2. Densidad del grafo" << endl;
                    cout << "3. Es conexo" << endl;
                    cout << "4. Es fuertemente conexo" << endl;
                    cout << "5. BFS" << endl;
                    cout << "6. DFS" << endl;
                    cout<<"Para salir del bucle insertar cualquier numero"<<endl;

                    cin >> metodo;
                    switch (metodo) {
                        case 1: {
                            graph1->display();
                            break;
                        }
                        case 2: {
                            if (graph1->isDense()) {
                                cout << "Es un grado denso" << endl;
                                cout << "Su densidad es " << graph1->density() << endl;
                            } else {
                                cout << "No es un grafo denso" << endl;
                                cout << "Su densidad es " << graph1->density() << endl;
                            }
                            break;
                        }
                        case 3: {
                            if (graph1->isConnected()) { cout << "Es un grafo conexo" << endl; }
                            else { cout << "No es un grafo conexo" << endl; }
                            break;
                        }
                        case 4: {
                            if (graph1->isStronglyConnected()) { cout << "Es un fuertemente grafo conexo" << endl; }
                            else { cout << "No es un grafo fuertemente conexo" << endl; }
                            break;
                        }
                        case 5: {
                            cout << "BFS desde el vertice A" << endl;
                            bfs<int, float> bfs_(graph1, "A");
                            bfs_.apply()->display();
                            break;
                        }
                        case 6: {
                            cout << "DFS desde el vertice A" << endl;
                            dfs<int, float> dfs_(graph1, "A");
                            dfs_.apply()->display();
                            break;
                        }

                    }
                }while (metodo <= 6 && 1 <= metodo);
                break;
            }
            case 3: {
                Graph<int, float> *graph2 = new DirectedGraph<int, float>;

                graph2->insertVertex("A", 1);
                graph2->insertVertex("B", 2);
                graph2->insertVertex("C", 3);
                graph2->insertVertex("D", 4);
                graph2->insertVertex("E", 5);
                graph2->insertVertex("F", 6);
                graph2->insertVertex("G", 7);
                graph2->insertVertex("H", 8);
                graph2->insertVertex("I", 9);
                graph2->insertVertex("J", 10);
                graph2->insertVertex("K", 11);
                graph2->insertVertex("L", 12);
                graph2->insertVertex("M", 13);
                graph2->insertVertex("N", 14);
                graph2->insertVertex("O", 15);
                graph2->insertVertex("P", 16);
                graph2->insertVertex("Q", 17);
                graph2->insertVertex("R", 18);

                graph2->createEdge("A", "D", 19);
                graph2->createEdge("A", "C", 12);

                graph2->createEdge("B", "D", 11);
                graph2->createEdge("B", "A", 17);

                graph2->createEdge("C", "A", 13);
                graph2->createEdge("C", "B", 14);
                graph2->createEdge("C", "M", 10);

                graph2->createEdge("D", "B", 18);
                graph2->createEdge("D", "C", 15);
                graph2->createEdge("D", "E", 22);

                graph2->createEdge("E", "F", 21);
                graph2->createEdge("E", "G", 29);
                graph2->createEdge("E", "M", 14);

                graph2->createEdge("F", "C", 17);
                graph2->createEdge("F", "E", 12);
                graph2->createEdge("F", "G", 25);
                graph2->createEdge("F", "K", 19);

                graph2->createEdge("G", "E", 16);
                graph2->createEdge("G", "I", 24);
                graph2->createEdge("G", "F", 10);
                graph2->createEdge("G", "Q", 11);
                graph2->createEdge("G", "R", 23);

                graph2->createEdge("H", "I", 21);
                graph2->createEdge("H", "K", 14);

                graph2->createEdge("I", "J", 15);

                graph2->createEdge("J", "H", 21);
                graph2->createEdge("J", "L", 17);
                graph2->createEdge("J", "P", 13);

                graph2->createEdge("K", "L", 28);
                graph2->createEdge("K", "M", 12);

                graph2->createEdge("L", "K", 19);
                graph2->createEdge("L", "N", 21);

                graph2->createEdge("M", "K", 11);
                graph2->createEdge("M", "N", 27);
                graph2->createEdge("M", "O", 16);

                graph2->createEdge("N", "L", 20);
                graph2->createEdge("N", "M", 17);

                graph2->createEdge("O", "N", 30);

                graph2->createEdge("P", "I", 32);

                graph2->createEdge("Q", "G", 31);
                graph2->createEdge("Q", "R", 13);

                graph2->createEdge("R", "G", 10);
                graph2->createEdge("R", "Q", 35);


                // Create and open a text file
                ofstream MyFile;
                MyFile.open("graph3.dot");
                graph2->display_file(MyFile);
                // Close the file
                MyFile.close();

                do {
                    cout << "\n\n Elija el metodo " << endl;
                    cout << "1. Mostrar grafo" << endl;
                    cout << "2. Densidad del grafo" << endl;
                    cout << "3. Es conexo" << endl;
                    cout << "4. Es fuertemente conexo" << endl;
                    cout << "5. BFS" << endl;
                    cout << "6. DFS" << endl;
                    cout<<"Para salir del bucle insertar cualquier numero"<<endl;

                    cin >> metodo;
                    switch (metodo) {
                        case 1: {
                            graph2->display();
                            break;
                        }
                        case 2: {
                            if (graph2->isDense()) {
                                cout << "Es un grado denso" << endl;
                                cout << "Su densidad es " << graph2->density() << endl;
                            } else {
                                cout << "No es un grafo denso" << endl;
                                cout << "Su densidad es " << graph2->density() << endl;
                            }
                            break;
                        }
                        case 3: {
                            if (graph2->isConnected()) { cout << "Es un grafo conexo" << endl; }
                            else { cout << "No es un grafo conexo" << endl; }
                            break;
                        }
                        case 4: {
                            if (graph2->isStronglyConnected()) { cout << "Es un fuertemente grafo conexo" << endl; }
                            else { cout << "No es un grafo fuertemente conexo" << endl; }
                            break;
                        }
                        case 5: {
                            cout << "BFS desde el vertice A" << endl;
                            bfs<int, float> bfs_(graph2, "A");
                            bfs_.apply()->display();
                            break;
                        }
                        case 6: {
                            cout << "DFS desde el vertice A" << endl;
                            dfs<int, float> dfs_(graph2, "A");
                            dfs_.apply()->display();
                            break;
                        }

                    }
                }while (metodo <= 6 && 1 <= metodo);
                break;

            }
        }
    }

    void GNDirigido() {
        cout << "Seleccione el grafo (1 al 3) que desee: ";
        int a;
        cin >> a;
        switch (a) {
            case 1: {
                Graph<int, float> *graph = new UnDirectedGraph<int, float>;

                graph->insertVertex("A", 1);
                graph->insertVertex("B", 2);
                graph->insertVertex("C", 3);
                graph->insertVertex("D", 4);
                graph->insertVertex("E", 5);
                graph->insertVertex("F", 6);
                graph->insertVertex("G", 7);
                graph->insertVertex("H", 8);

                graph->createEdge("A", "B", 1);
                graph->createEdge("A", "D", 5);
                graph->createEdge("A", "C", 3);
                graph->createEdge("B", "D", 6);
                graph->createEdge("C", "D", 4);
                graph->createEdge("D", "F", 2);
                graph->createEdge("G", "H", 8);
                graph->createEdge("C", "E", 7);
                graph->createEdge("E", "G", 4);
                graph->createEdge("E", "F", 9);
                graph->createEdge("H", "F", 3);

                // Create and open a text file
                ofstream MyFile;
                MyFile.open("udgraph1.dot");
                graph->display_file(MyFile);
                // Close the file
                MyFile.close();

                do {
                    cout << "\n\n Elija el metodo " << endl;
                    cout << "1. Mostrar grafo" << endl;
                    cout << "2. Densidad del grafo" << endl;
                    cout << "3. Es conexo" << endl;
                    cout << "4. Es fuertemente conexo" << endl;
                    cout << "5. BFS" << endl;
                    cout << "6. DFS" << endl;
                    cout << "7. Kruskal" << endl;
                    cout << "8. Prim" << endl;
                    cout<<"Para salir del bucle insertar cualquier numero"<<endl;

                    cin >> metodo;
                    switch (metodo) {
                        case 1: {
                            graph->display();
                            break;
                        }
                        case 2: {
                            if (graph->isDense()) {
                                cout << "Es un grado denso" << endl;
                                cout << "Su densidad es " << graph->density() << endl;
                            } else {
                                cout << "No es un grafo denso" << endl;
                                cout << "Su densidad es " << graph->density() << endl;
                            }
                            break;
                        }
                        case 3: {
                            if (graph->isConnected()) { cout << "Es un grafo conexo" << endl; }
                            else { cout << "No es un grafo conexo" << endl; }
                            break;
                        }
                        case 4: {
                            if (graph->isStronglyConnected()) { cout << "Es un fuertemente grafo conexo" << endl; }
                            else { cout << "No es un grafo fuertemente conexo" << endl; }
                            break;
                        }
                        case 5: {
                            cout << "BFS desde el vertice A" << endl;
                            bfs<int, float> bfs_(graph, "A");
                            bfs_.apply()->display();
                            break;
                        }
                        case 6: {
                            cout << "DFS desde el vertice A" << endl;
                            dfs<int, float> dfs_(graph, "A");
                            dfs_.apply()->display();
                            break;
                        }
                        case 7: {
                            cout << "Kruskal" << endl;
                            Kruskal<int, float> kruskal(graph);    /*Undirected graph */
                            UnDirectedGraph<int, float> *result = kruskal.apply();//return a tree
                            result->display();

                            break;
                        }

                        case 8: {
                            cout << "Prim" << endl;
                            prim<int, float> prim_(graph, "A");    /*Undirected graph */
                            UnDirectedGraph<int, float> *result = prim_.apply();//return a tree
                            result->display();
                            break;
                        }
                        case 9: {
                            cout<< "A*"<<endl;


                            unordered_map<string, float> heur;
                            heur["A"] = 36;
                            heur["B"] = 39;
                            heur["C"] = 31;
                            heur["D"] = 30;
                            heur["E"] = 34;
                            heur["F"] = 32;
                            heur["G"] = 21;
                            heur["H"] = 19;
                            heur["I"] = 0;


                            astar<int,float>* Astarr = new astar<int,float> (graph,"A","I",heur);
                            Astarr->display();
                            Astarr->apply()->display();

                        }
                    }
                }while (metodo <= 9 && 1 <= metodo);
                break;

            }
            case 2: {
                Graph<int, float> *graph1 = new UnDirectedGraph<int, float>;
                graph1->insertVertex("A", 1);
                graph1->insertVertex("B", 2);
                graph1->insertVertex("C", 3);
                graph1->insertVertex("D", 4);
                graph1->insertVertex("E", 5);
                graph1->insertVertex("F", 6);
                graph1->insertVertex("G", 7);

                graph1->createEdge("A", "B", 7);
                graph1->createEdge("A", "D", 5);
                graph1->createEdge("B", "C", 8);
                graph1->createEdge("B", "D", 9);
                graph1->createEdge("E", "D", 15);
                graph1->createEdge("B", "E", 7);
                graph1->createEdge("C", "E", 5);
                graph1->createEdge("D", "F", 6);
                graph1->createEdge("F", "G", 11);
                graph1->createEdge("E", "F", 8);
                graph1->createEdge("E", "G", 9);

                // Create and open a text file
                ofstream MyFile;
                MyFile.open("udgraph2.dot");
                graph1->display_file(MyFile);
                // Close the file
                MyFile.close();

                do {
                    cout << "\n\n Elija el metodo " << endl;
                    cout << "1. Mostrar grafo" << endl;
                    cout << "2. Densidad del grafo" << endl;
                    cout << "3. Es conexo" << endl;
                    cout << "4. Es fuertemente conexo" << endl;
                    cout << "5. BFS" << endl;
                    cout << "6. DFS" << endl;
                    cout << "7. Kruskal" << endl;
                    cout << "8. Prim" << endl;
                    cout<<"Para salir del bucle insertar cualquier numero"<<endl;

                    cin >> metodo;
                    switch (metodo) {
                        case 1: {
                            graph1->display();
                            break;
                        }
                        case 2: {
                            if (graph1->isDense()) {
                                cout << "Es un grado denso" << endl;
                                cout << "Su densidad es " << graph1->density() << endl;
                            } else {
                                cout << "No es un grafo denso" << endl;
                                cout << "Su densidad es " << graph1->density() << endl;
                            }
                            break;
                        }
                        case 3: {
                            if (graph1->isConnected()) { cout << "Es un grafo conexo" << endl; }
                            else { cout << "No es un grafo conexo" << endl; }
                            break;
                        }
                        case 4: {
                            if (graph1->isStronglyConnected()) { cout << "Es un fuertemente grafo conexo" << endl; }
                            else { cout << "No es un grafo fuertemente conexo" << endl; }
                            break;
                        }
                        case 5: {
                            cout << "BFS desde el vertice A" << endl;
                            bfs<int, float> bfs_(graph1, "A");
                            bfs_.apply()->display();
                            break;
                        }
                        case 6: {
                            cout << "DFS desde el vertice A" << endl;
                            dfs<int, float> dfs_(graph1, "A");
                            dfs_.apply()->display();
                            break;
                        }
                        case 7: {
                            cout << "Kruskal" << endl;
                            Kruskal<int, float> kruskal(graph1);    /*Undirected graph */
                            UnDirectedGraph<int, float> *result = kruskal.apply();//return a tree
                            result->display();
                            break;
                        }

                        case 8: {
                            cout << "Prim" << endl;
                            prim<int, float> prim_(graph1, "A");    /*Undirected graph */
                            UnDirectedGraph<int, float> *result = prim_.apply();//return a tree
                            result->display();
                            break;
                        }
                        case 9: {
                            cout<< "A*"<<endl;

                            unordered_map<string, float> heur;
                            heur["A"] = 36;
                            heur["B"] = 39;
                            heur["C"] = 31;
                            heur["D"] = 30;
                            heur["E"] = 34;
                            heur["F"] = 32;
                            heur["G"] = 21;
                            heur["H"] = 19;
                            heur["I"] = 0;


                            astar<int,float>* Astarr = new astar<int,float> (graph1,"A","I",heur);
                            Astarr->display();
                            Astarr->apply()->display();

                        }
                    }
                }while (metodo <= 9 && 1 <= metodo);
                break;
            }
            case 3: {
                Graph<int, float> *graph2 = new UnDirectedGraph<int, float>;
                graph2->insertVertex("A", 1);
                graph2->insertVertex("B", 2);
                graph2->insertVertex("C", 3);
                graph2->insertVertex("D", 4);
                graph2->insertVertex("E", 5);
                graph2->insertVertex("F", 6);

                graph2->createEdge("A", "B", 6);
                graph2->createEdge("A", "C", 1);
                graph2->createEdge("A", "D", 5);
                graph2->createEdge("B", "C", 5);
                graph2->createEdge("C", "D", 5);
                graph2->createEdge("B", "E", 3);
                graph2->createEdge("F", "E", 6);
                graph2->createEdge("C", "E", 6);
                graph2->createEdge("C", "F", 4);
                graph2->createEdge("E", "F", 6);
                graph2->createEdge("D", "F", 2);

                // Create and open a text file
                ofstream MyFile;
                MyFile.open("udgraph3.dot");
                graph2->display_file(MyFile);
                // Close the file
                MyFile.close();

                do {
                    cout << "\n\n Elija el metodo " << endl;
                    cout << "1. Mostrar grafo" << endl;
                    cout << "2. Densidad del grafo" << endl;
                    cout << "3. Es conexo" << endl;
                    cout << "4. Es fuertemente conexo" << endl;
                    cout << "5. BFS" << endl;
                    cout << "6. DFS" << endl;
                    cout << "7. Kruskal" << endl;
                    cout << "8. Prim" << endl;
                    cout << "9. A*" << endl;
                    cout<<"Para salir del bucle insertar cualquier numero"<<endl;

                    cin >> metodo;
                    switch (metodo) {
                        case 1: {
                            graph2->display();
                            break;
                        }
                        case 2: {
                            if (graph2->isDense()) {
                                cout << "Es un grado denso" << endl;
                                cout << "Su densidad es " << graph2->density() << endl;
                            } else {
                                cout << "No es un grafo denso" << endl;
                                cout << "Su densidad es " << graph2->density() << endl;
                            }
                            break;
                        }
                        case 3: {
                            if (graph2->isConnected()) { cout << "Es un grafo conexo" << endl; }
                            else { cout << "No es un grafo conexo" << endl; }
                            break;
                        }
                        case 4: {
                            if (graph2->isStronglyConnected()) { cout << "Es un fuertemente grafo conexo" << endl; }
                            else { cout << "No es un grafo fuertemente conexo" << endl; }
                            break;
                        }
                        case 5: {
                            cout << "BFS desde el vertice A" << endl;
                            bfs<int, float> bfs_(graph2, "A");
                            bfs_.apply()->display();
                            break;
                        }
                        case 6: {
                            cout << "DFS desde el vertice A" << endl;
                            dfs<int, float> dfs_(graph2, "A");
                            dfs_.apply()->display();
                            break;
                        }
                        case 7: {
                            cout << "Kruskal" << endl;
                            Kruskal<int, float> kruskal(graph2);    /*Undirected graph */
                            UnDirectedGraph<int, float> *result = kruskal.apply();//return a tree
                            result->display();
                            break;
                        }

                        case 8: {
                            cout << "Prim" << endl;
                            prim<int, float> prim_(graph2, "A");    /*Undirected graph */
                            UnDirectedGraph<int, float> *result = prim_.apply();//return a tree
                            result->display();
                            break;
                        }
                        case 9: {
                            cout<< "A*"<<endl;


                            unordered_map<string, float> heur;
                            heur["A"] = 36;
                            heur["B"] = 39;
                            heur["C"] = 31;
                            heur["D"] = 30;
                            heur["E"] = 34;
                            heur["F"] = 32;
                            heur["G"] = 21;
                            heur["H"] = 19;
                            heur["I"] = 0;


                            astar<int,float>* Astarr = new astar<int,float> (graph2,"A","I",heur);
                            Astarr->display();
                            Astarr->apply()->display();

                        }
                    }
                }while (metodo <= 9 && 1 <= metodo);
                break;
            }
        }
    }

    void Ejemplos(){
        do {
            cout << "\n\nSeleccione tipo de Grafo" << endl;
            cout << "1. Grafo Dirigido" << endl;
            cout << "2. Grafo No Dirigido" << endl;
            cout << "Ingrese una opcion : ";
            cin >> input_Case;
            switch (input_Case) {
                case 1: {
                    GDirigido();
                    break;
                }
                case 2: {
                    GNDirigido();
                    break;
                }
            }
        }
        while (input_Case < 3 && 1 <= input_Case);
    }

    void Parsers(){
        do {
            cout << "\n\nSeleccione el json a ejecutar" << endl;
            cout<< "1. Aeropuertos internacionales"<<endl;
            cout<< "2. Aeropuertos nacionales"<<endl;
            cin >> input_Case;
            switch (input_Case) {
                case 1: {
                    executeParser(file::airports);
                    break;
                }
                case 2: {
                    executeParser(file::pe);
                    break;
                }
            }
        }
        while (input_Case < 3 && 1 <= input_Case);
    }

    void executeExamples() {
        do {
            cout << "\n\nMenu de opciones" << endl;
            cout << "1. Ejemplos" << endl;
            cout << "2. Parser" << endl;
            cout << "3. SALIR" << endl << endl;
            cout<<"Para salir del bucle insertar cualquier numero"<<endl;
            cout << "Ingrese una opcion : ";
            cin >> input_Case;
            switch (input_Case) {
                case 1: {
                    Ejemplos();
                    break;
                }
                case 2: {
                    Parsers();
                    break;
                }
            }
        } while (input_Case < 3 && 1 <= input_Case);
    }


}



void Tester::executeParser(file json_file) {
    Parser parser;
    parser.generateJson(json_file);
    UnDirectedGraph<Airport, double>* unDirectedGraph = new UnDirectedGraph<Airport, double>;
    DirectedGraph<Airport, double>* directedGraph = new DirectedGraph<Airport, double>;

    parser.generateUndirectedGraph(unDirectedGraph);
    parser.generateDirectedGraph(directedGraph);
    do {
        cout << "\n\nSeleccione tipo de Grafo" << endl;
        cout << "1. Grafo No Dirigido" << endl;
        cout << "2. Grafo Dirigido" << endl;
        cout << "Ingrese una opcion : ";
        cin >> input_Case;
        switch (input_Case) {
            case 1: {
                cout << "Seleccione el grafo (1 al 3) que desee: ";
                int metodo;

                // Create and open a text file
                ofstream MyFile;
                MyFile.open("udgraph1.dot");
                unDirectedGraph->display_file(MyFile);
                // Close the file
                MyFile.close();

                do {
                    cout << "\n\n Elija el metodo " << endl;
                    cout << "1. Mostrar grafo" << endl;
                    cout << "2. Densidad del grafo" << endl;
                    cout << "3. Es conexo" << endl;
                    cout << "4. Es fuertemente conexo" << endl;
                    cout << "5. BFS" << endl;
                    cout << "6. DFS" << endl;
                    cout << "7. Kruskal" << endl;
                    cout << "8. Prim" << endl;
                    cout << "9. Dijkstra" << endl;
                    cout << "10. Floyd Warshall" << endl;

                    cout<<"Para salir del bucle insertar cualquier numero"<<endl;

                    cin >> metodo;
                    switch (metodo) {
                        case 1: {
                            unDirectedGraph->display();
                            break;
                        }
                        case 2: {
                            if (unDirectedGraph->isDense()) {
                                cout << "Es un grado denso" << endl;
                                cout << "Su densidad es " << unDirectedGraph->density() << endl;
                            } else {
                                cout << "No es un grafo denso" << endl;
                                cout << "Su densidad es " << unDirectedGraph->density() << endl;
                            }
                            break;
                        }
                        case 3: {
                            if (unDirectedGraph->isConnected()) { cout << "Es un grafo conexo" << endl; }
                            else { cout << "No es un grafo conexo" << endl; }
                            break;
                        }
                        case 4: {
                            if (unDirectedGraph->isStronglyConnected()) { cout << "Es un fuertemente grafo conexo" << endl; }
                            else { cout << "No es un grafo fuertemente conexo" << endl; }
                            break;
                        }
                        case 5: {
                            string input;
                            cout<<"Por favor ingrese el ID del aeropuerto"<<endl;
                            cin>>input;
                            cout << "BFS " << endl;
                            bfs<Airport, double> bfs_(unDirectedGraph, input);
                            bfs_.apply()->display();
                            break;
                        }
                        case 6: {
                            string input;
                            cout<<"Por favor ingrese el ID del aeropuerto"<<endl;
                            cin>>input;
                            cout << "DFS " << endl;
                            dfs<Airport, double> dfs_(unDirectedGraph, input);
                            dfs_.apply()->display();
                            break;
                        }
                        case 7: {

                            cout << "Kruskal" << endl;
                            Kruskal<Airport, double> kruskal(unDirectedGraph);    /*Undirected graph */
                            UnDirectedGraph<Airport, double> *result = kruskal.apply();//return a tree
                            result->display();

                            break;
                        }

                        case 8: {
                            string input;
                            cout<<"Por favor ingrese el ID del aeropuerto"<<endl;
                            cin>>input;
                            cout << "Prim" << endl;
                            prim<Airport, double> prim_(unDirectedGraph, input);    /*Undirected graph */
                            UnDirectedGraph<Airport, double> *result = prim_.apply();//return a tree
                            result->display();
                            break;
                        }
                        case 9: {
                            string input;
                            cout<<"Por favor ingrese el ID del aeropuerto"<<endl;
                            cin>>input;
                            cout << "Dijkstra" << endl;
                            dijkstra<Airport, double> dijkstra_(unDirectedGraph, input);
                            DirectedGraph<Airport, double> *result = dijkstra_.apply();
                            result->display();
                            break;

                        }   case 10: {
                            cout << "Floyd Warshall" << endl;
                            floyd_warshall<Airport, double> floyd_warshall_(unDirectedGraph);
                            DirectedGraph<Airport, double> *result = floyd_warshall_.apply();
                            result->display();
                            break;
                        }

                    }
                }while (metodo <= 10 && 1 <= metodo);

                break;
            }
            case 2: {
                ofstream MyFile;
                MyFile.open("graph1.dot");
                directedGraph->display_file(MyFile);
                // Close the file
                MyFile.close();

                do {
                    cout << "\n\n Elija el metodo " << endl;
                    cout << "1. Mostrar grafo" << endl;
                    cout << "2. Densidad del grafo" << endl;
                    cout << "3. Es conexo" << endl;
                    cout << "4. Es fuertemente conexo" << endl;
                    cout << "5. BFS" << endl;
                    cout << "6. DFS" << endl;
                    cout << "7. Dijkstra" << endl;
                    cout << "8. Bellman Ford " << endl;
                    cout << "9. Floy Warshall" << endl;
                    cout<<"Para salir del bucle insertar cualquier numero"<<endl;

                    cin >> metodo;

                    switch (metodo) {
                        case 1: {
                            directedGraph->display();
                            break;
                        }

                        case 2: {
                            if (directedGraph->isDense()) {
                                cout << "Es un grado denso" << endl;
                                cout << "Su densidad es " << directedGraph->density() << endl;
                            } else {
                                cout << "No es un grafo denso" << endl;
                                cout << "Su densidad es " << directedGraph->density() << endl;
                            }
                            break;
                        }
                        case 3: {
                            if (directedGraph->isConnected()) { cout << "Es un grafo conexo" << endl; }
                            else { cout << "No es un grafo conexo" << endl; }
                            break;
                        }
                        case 4: {
                            if (directedGraph->isStronglyConnected()) { cout << "Es un fuertemente grafo conexo" << endl; }
                            else { cout << "No es un grafo fuertemente conexo" << endl; }
                            break;
                        }
                        case 5: {
                            string input;
                            cout<<"Por favor ingrese el ID del aeropuerto"<<endl;
                            cin>>input;
                            cout << "BFS" << endl;
                            bfs<Airport, double> bfs_(directedGraph, input);
                            bfs_.apply()->display();

                            break;
                        }
                        case 6: {
                            string input;
                            cout<<"Por favor ingrese el ID del aeropuerto"<<endl;
                            cin>>input;
                            cout << "DFS" << endl;
                            dfs<Airport, double> dfs_(directedGraph, input);
                            dfs_.apply()->display();
                            break;
                        }
                        case 7: {
                            string input;
                            cout<<"Por favor ingrese el ID del aeropuerto"<<endl;
                            cin>>input;
                            cout << "Dijkstra" << endl;
                            dijkstra<Airport, double> dijkstra_(directedGraph, input);    /*Undirected graph */
                            DirectedGraph<Airport, double> *result = dijkstra_.apply();//return a tree
                            result->display();
                            break;
                        }
                        case 8: {
                            string input;
                            cout<<"Por favor ingrese el ID del aeropuerto"<<endl;
                            cin>>input;
                            cout << "Bellman Ford" << endl;
                            bellmanford<Airport, double> bellmanford_(directedGraph, input);
                            DirectedGraph<Airport, double> *result = bellmanford_.apply();
                            result->display();
                            break;

                        }
                        case 9: {
                            cout << "Floyd Warshall" << endl;
                            floyd_warshall<Airport, double> floyd_warshall_(directedGraph);
                            DirectedGraph<Airport, double> *result = floyd_warshall_.apply();
                            result->display();
                            break;
                        }

                    }
                }while (metodo <= 8 && 1 <= metodo);
                break;
            }
        }
    }
    while (input_Case < 9 && 1 <= input_Case);
}


/*
 Graph<char, int>* gra = new UnDirectedGraph<char, int>;
    gra->insertVertex("A", 'A');
    gra->insertVertex("B",'B');
    gra->insertVertex("C",'C');
    gra->insertVertex("D", 'D');
    gra->insertVertex("E", 'E');
    gra->insertVertex("F", 'F');
    gra->insertVertex("G", 'G');
    gra->insertVertex("H", 'H');
    gra->insertVertex("I", 'I');

    unordered_map<string, int> heur;
    heur["A"] = 36;
    heur["B"] = 39;
    heur["C"] = 31;
    heur["D"] = 30;
    heur["E"] = 34;
    heur["F"] = 32;
    heur["G"] = 21;
    heur["H"] = 19;
    heur["I"] = 0;

    gra->createEdge("A","B",22);
    gra->createEdge("A","C",9);
    gra->createEdge("A","D",12);
    gra->createEdge("C","B",35);
    gra->createEdge("C","D",4);
    gra->createEdge("D","E",33);
    gra->createEdge("D","I",30);
    gra->createEdge("B","F",36);
    gra->createEdge("B","H",34);
    gra->createEdge("C","F",42);
    gra->createEdge("C","E",65);
    gra->createEdge("D","E",33);
    gra->createEdge("D","I",30);
    gra->createEdge("E","G",18);
    gra->createEdge("E","F",23);
    gra->createEdge("F","H",24);
    gra->createEdge("G","F",39);
    gra->createEdge("G","H",25);
    gra->createEdge("G","I",21);
    gra->createEdge("I","H",19);

    astar<char,int>* Astarr = new astar<char,int> (gra,"A","I",heur);
    Astarr->display();
    Astarr->apply()->display();
 */


#endif //TESTER_H

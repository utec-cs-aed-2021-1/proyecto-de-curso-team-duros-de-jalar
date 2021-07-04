
#ifndef CLIONPROYECT_MENU_H
#define CLIONPROYECT_MENU_H
#include <iostream>
#include <cstdlib>
#include "UndirectedGraph.h"
#include "DirectedGraph.h"
#include "Algorithms/prim.h"
#include "Algorithms/kruskal.h"
#include "Algorithms/bfs.h"
#include "Algorithms/dfs.h"

using namespace std;
struct Menu {
    int input_Case{};

    void correr_menu()
    {
        do {
            cout << "\n\nMenu de opciones" << endl;
            cout << "1. Grafo Dirigido" << endl;
            cout << "2. Grafo No Dirigido" << endl;
            cout << "3. SALIR" << endl<<endl;
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

        }while (input_Case>3 || 1>input_Case);
    }


    void GDirigido(){

    }
    void GNDirigido(){
        cout<<"Seleccione el grafo (1 al 3) que desea ver: ";
        int a; cin>>a;
        switch(a){
            case 1:{
                Graph<int, float>* graph = new UnDirectedGraph<int,float> ;

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

                graph->display();
                if(graph->isConnected()){cout<<"Es un grafo conexo"<<endl;}
                else{cout<<"Es un grafo conexo"<<endl;}

                dfs<int,float> dfs_ (graph, "A");
                dfs_.apply()->display();
                bfs<int,float> bfs_ (graph, "A");
                bfs_.apply()->display();
                break;
            }
            case 2:{
                Graph<int, float>* graph1 = new UnDirectedGraph<int,float> ;
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

                graph1->display();
                if(graph1->isConnected()){cout<<"Es un grafo conexo"<<endl;}
                else{cout<<"Es un grafo conexo"<<endl;}
                dfs<int,float> dfs_ (graph1, "A");
                dfs_.apply()->display();
                bfs<int,float> bfs_ (graph1, "A");
                bfs_.apply()->display();
                break;
            }
            case 3:{
                Graph<int,float>* graph2 = new UnDirectedGraph<int,float> ;
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

                graph2->display();
                if(graph2->isConnected()){cout<<"Es un grafo conexo"<<endl;}
                else{cout<<"Es un grafo conexo"<<endl;}
                dfs<int,float> dfs_ (graph2, "A");
                dfs_.apply()->display();
                bfs<int,float> bfs_ (graph2, "A");
                bfs_.apply()->display();

                break;
            }
        }
    }

};
#endif //CLIONPROYECT_MENU_H

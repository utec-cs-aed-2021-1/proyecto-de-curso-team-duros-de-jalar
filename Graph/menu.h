#include <iostream>
#include <cstdlib>

using namespace std;
struct Menu {
    int input_Case{};

    void correr_menu()
    {
        int input =0;

        do {
            cout << "\n\nMenu de opciones" << endl;
            cout << "1. Grafo Dirigido" << endl;
            cout << "2. Grafo No Dirigido" << endl;
            cout << "3. SALIR" << endl<<endl;
            cout << "Ingrese una opcion : ";
            cin >> input_Case;
        }while (input_Case>3 || 1>input_Case);

    }

};

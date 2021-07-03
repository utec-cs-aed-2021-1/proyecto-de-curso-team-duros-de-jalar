# Algoritmos y Estructura de Datos
## Proyecto sobre Grafos
--------

## Integrantes ✒️

- Luis Gutiérrez [Luis-ntonio]
- Marcos Ayala [Marcos-1001]
- Alexandra Shulca [Alexandra-SR]

----

## Objetivos Principales :dart:

El proyecto del curso consiste en implementar una estructura de datos de grafo y un file parser. La estructura debe soportar los métodos y algoritmos descritos a continuacion:

## Comenzando 🚀

### Pre-requisitos 📋

```
C++ 17
```

### Despliegue 📦

**1.** Clonar el repositorio del proyecto.

**2.** Realizar el Build del proyecto utilizando el IDE CLion.

**3.** Ejecutar el programa


## Graph data structure 🚀

* El grafo debe ser dinámico (inserciones. eliminaciones, búsquedas, ...)
* Se debe implementar los dos tipos de grafos: dirigidos y no-dirigidos.
* No considerar loops ni multi-arista.


### Methods:
```cpp
bool insertVertex(string id, V data); // Creates a new vertex in the graph with some data and an ID

bool createEdge(string start, string end, E data); // Creates a new edge in the graph with some data

bool deleteVertex(string id); // Deletes a vertex in the graph

bool deleteEdge(string start, string end); // Deletes an edge in the graph, it is not possible to search by the edge value, since it can be repeated

E &operator()(string start, string end); // Gets the value of the edge from the start and end vertexes

float density() const; // Calculates the density of the graph

bool isDense(float threshold = 0.5) const; // Calculates the density of the graph, and determine if it is dense dependening on a threshold value

bool isConnected(); // Detect if the graph is connected

bool isStronglyConnected() throw(); // Detect if the graph is strongly connected (only for directed graphs)

bool empty(); // If the graph is empty

void clear(); // Clears the graph
```
### Especificaciones del algoritmo de los métodos del Grafo NO DIRIGIDO (UnDirectedGraph)
```cpp
template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::insertVertex(string id, TV vertex) {
    if (this->vertexes.find(id) != this->vertexes.end())
        return false;
    auto *new_vertex = new Vertex<TV, TE>;
    new_vertex->data = vertex;
    new_vertex->id = id;
    this->vertexes[id] = new_vertex;
    return true;
}
```
Para insertar un nuevo vértice, principalmente, necesitamos verificar si existe un otro con el mismo id.
En caso, no exista un vértice así, entonces creamos un objeto Vertex, le asignamos la data y un id, para finalmente
insertarlo en el unordered_map.


```cpp

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::createEdge(string id1, string id2, TE w) {
    if (this->vertexes.find(id1) == this->vertexes.end() && this->vertexes.find(id2) == this->vertexes.end())
        return false;

    auto *new_edge = new Edge<TV, TE>;
    new_edge->vertexes[0] = this->vertexes[id1];
    new_edge->vertexes[1] = this->vertexes[id2];
    new_edge->weight = w;

    this->vertexes[id1]->edges.push_back(new_edge);

    auto *new_edge1 = new Edge<TV, TE>;
    new_edge1->vertexes[1] = this->vertexes[id1];
    new_edge1->vertexes[0] = this->vertexes[id2];
    new_edge1->weight = w;

    this->vertexes[id2]->edges.push_back(new_edge1);
    E++;
    return true;
}
```

createEdge en Undirected graph verifica si los vértices que se desean 
conectar existen en el grafo. Si existen, se conectan entre ambos;
es decir, el id1 se conecta con el id2 y viceversa. Finalmente se
incrementa el tamaño de edges y retorna true.

```cpp
template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::createEdge(string id1, string id2, TE w) {
    if (this->vertexes.find(id1) == this->vertexes.end() && this->vertexes.find(id2) == this->vertexes.end())
        return false;

    auto *new_edge = new Edge<TV, TE>;
    new_edge->vertexes[0] = this->vertexes[id1];
    new_edge->vertexes[1] = this->vertexes[id2];
    new_edge->weight = w;

    this->vertexes[id1]->edges.push_back(new_edge);
    E++;
    return true;
}
```
La función createEdge en Directed graph verifica si los vértices que se desean conectar existen en el grafo. Si existen, se conectan unilateralmente; es decir, el id1 se conecta con el id2.
Finalmente se inserta en el vector de edges el nuevo edge y retorna true.


```cpp
template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::deleteVertex(string id) {
    if (this->vertexes.find(id) == this->vertexes.end())
        return false;
    deleteEdge(id);
    for (auto i = this->vertexes.begin(); i != this->vertexes.end(); i++) { //Revisa cada vértice a excepción del que se va a eliminar
        if ((*i).second != this->vertexes[id]) {
            auto list_of_edges = (*i).second->edges;

            for (auto j = list_of_edges.begin(); j != list_of_edges.end(); j++) { //Busco si existe una arista que conecte con el vértice id y la borro
                if ((*j)->vertexes[1] == this->vertexes[id]) {
                    (list_of_edges).erase(j);
                    break;
                }
            }
        }
    }
    this->vertexes.erase(id);
    return true;
}
```
La función deleteVertex en DirectedGraph recibe el id del vértice que se desea eliminar. En primer lugar, verifica si el vértice existe en el grafo, si no existe retorna false; caso contrario, procede a iterar por todos los
vértices (excluyendo al que se desea eliminar) y verifica si está conectados con el vértice buscado, en caso existiera una arista, se elimina.
Cuando no existan aristas, se elimina el vértice sin complicaciones.

```cpp
template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteVertex(string id) {
if (this->vertexes.find(id) == this->vertexes.end())
return false;

deleteEdge(id);
this->vertexes.erase(id);

return true;
}
```

El deleteVertex para el undirected graph, verifica si existe el vértice que se desea 
eliminar, si existe se llama a la función deleteEdge para la eliminación de las 
aristas que se conectan al vértice. Finalmente, se elimina el vértice aislado.


```cpp
template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::empty() {
    return this->vertexes.size() == 0;
}
```
La función empty se encarga de verificar si el grafo se encuentra vacío o cuenta con algún vértice insertado.

```cpp
template<typename TV, typename TE>
void DirectedGraph<TV, TE>::clear() {
    while (!this->vertexes.empty()) {
        auto i = *this->vertexes.begin();
        deleteVertex(i.first);

    }
}
```
El objetivo de clear es, mientras el vector de vértices no esté vacío, toma el vértice
que se encuentra al inicio del vector y llama a la función deleteVertex.


```cpp
template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::findById(string id) {
    if (this->vertexes.find(id) == this->vertexes.end()) return false;
    return true;
}
```

El findById es un booleano que retorna verdadero en caso se encuentre 
un vector con el Id solicitado; caso contrario, retorna false.

````cpp
template<typename TV, typename TE>
void DirectedGraph<TV, TE>::displayVertex(string id) {
    if (this->vertexes.find(id) == this->vertexes.end())
        return;

    auto all_edges = (this->vertexes[id])->edges;
    auto ids = id;
    for (auto i: all_edges) {
        for (auto it = this->vertexes.begin(); it != this->vertexes.end(); ++it) {
            if (it->second == (*i).vertexes[1]) ids = it->first;
        }

        std::cout << "weight from vertex " << id << " to vertex " << ids << " is " << (*i).weight << endl;
    }
}
````
displayVertex muestra en consola el peso de las aristas conectadas
desde el vértice solicitado hasta los vértices conectados a este.

````cpp
template<typename TV, typename TE>
void DirectedGraph<TV, TE>::display() {
    for (auto i: this->vertexes) {
        displayVertex(i.first);
    }
}
````

La función display recorre el contenedor vertexes y por cada vértice, llama a la función displayVertex y muestra en pantalla todas las 
aristas y sus respectivos vértices que estan conectados dentro del grafo.

````c++
template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::isConnected() {
    for(auto &j : this->vertexes){
        std::unordered_set<string> visited;
        std::stack<Vertex<TV, TE> *> pila;

        visited.insert(j.first);

        for (auto i : j.second->edges) {
            Vertex<TV, TE> *ax = i->vertexes[1];
            if (visited.find(ax->id) == visited.end()) {
                pila.push(ax);
            }
        }

        while (!pila.empty()) {
            Vertex<TV, TE> * to_insert = pila.top();
            pila.pop();
            visited.insert(to_insert->id);

            for (auto i : to_insert->edges) {
                Vertex<TV, TE> *ax = i->vertexes[1];
                if (visited.find(ax->id) == visited.end()) {
                    pila.push(ax);
                }
            }
        }
        if (visited.size() == this->vertexes.size()){return  true;}
    }
    return false;
}
````

La funcion isconected tiene como objetivo, comprobar si desde el vértice solicitado
se puede llegar a todos los vertices del grafo. Par esta implementcación, implementamos 
una estuctura de código similar a la del bfs, anexa las aristas anexadas al vértice de inicio
para saber a qué vértices está conectado. Luego verifica si esos vértices ya se han visitado,
si no lo han sido, se añaden a la pila y se marca como visitado hasta verificar todos los vértices.
Finalmente, si el tamaño de la pila es igual a la cantidad de vértices, retorna true.

````c++

````



### Algorithms:
```cpp
//Given the graph
UndirectedGraph<char, int> graph;

//1- Generates a MST graph using the Kruskal approach (only for undirected graphs)
Kruskal<char, int> kruskal(&graph);
UndirectedGraph<char, int> result = kruskal.apply();//return a tree

//2- Generates a MST graph using the Prim approach (only for undirected graphs)
Prim<char, int> prim(&graph, "A");
UndirectedGraph<char, int> result = prim.apply();//return a tree

//3- A *
AStar<char, int> astar(&graph, "A", "Z", vector<int> heuristics);
UndirectedGraph<char, int> result = astar.apply();

```

### >kruskal.h
````cpp
UnDirectedGraph<TV, TE> apply(){
        this->minimal();
        G = new UnDirectedGraph<TV, TE>();
        for(pair<string, Vertex<TV, TE> *> vertex: aux_graph->getVertexes())
            G->insertVertex(vertex.first, vertex.second->data);
        for (auto edge : result){
            string aux1 , aux2;
            int k =0;
            for(pair<string, Vertex<TV, TE> *> vertex: aux_graph->getVertexes()){
                if (k == edge.u)
                    aux1 = vertex.first;
                if(k == edge.v)
                    aux2 = vertex.first;
                k++;
            }
            G->createEdge(aux1, aux2, edge.weight);
        }
        return *G;
   }

````

## JSON file parser
* Construye un grafo a partir de una archivo JSON de aereopuertos del mundo. 


### Methods:
```cpp
void clear(); // Clears parser saved atributes

void readJSON(); // Parses JSON file and saves data into class
// NOTE: each derived class has its own readJSON method

void uGraphMake(UndirectedGraph<string, double> &tempGraph); // Adds the parsed data into the specified undirected graph

void dGraphMake(DirectedGraph<string, double> &tempGraph); // Adds the parsed data into the specified directed graph
```

## [Git Karma Guidelines](http://karma-runner.github.io/5.2/dev/git-commit-msg.html)

```
<type>(<scope>): <subject>

<body>
```

### Allowed ```<type>``` values

* feat (new feature for the user, not a new feature for build script)
* fix (bug fix for the user, not a fix to a build script)
* docs (changes to the documentation)
* style (formatting, missing semi colons, etc)
* refactor (refactoring production code, eg. renaming a variable)
* test (adding missing tests, refactoring tests)
* chore (updating grunt tasks etc)

### Allowed ```<scope>``` values

* graph
* directedGraph
* undirectedGraph
* parser
* main
* tester

> **PD:** Puntos extras sobre Evaluación Continua si se implementa una GUI.

## Construido con 🛠️
* [CLion](https://www.jetbrains.com/clion/) - Utilizado para la compilación y testeo del proyecto

## Licencia 📄
Universidad de Ingenieria y Tecnología - UTEC
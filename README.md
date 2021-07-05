# Algoritmos y Estructura de Datos
## Proyecto sobre Grafos
--------

## Integrantes ✒️

- Luis Gutiérrez [Luis-ntonio] Participación: 100%
- Marcos Ayala [Marcos-1001] Participación: 100%
- Alexandra Shulca [Alexandra-SR] Participación: 100%

## Profesor 🦾

- Heider Sanchez Enriquez

## Asistentes de docencia
- Paolo Morey Tutiven
- Jorge Castillo Migone

----

## Objetivos Principales :dart:

El proyecto del curso consiste en implementar una estructura de datos de grafo y un file parser. La estructura debe soportar los métodos y algoritmos descritos a continuacion:

## Comenzando 🚀

### Pre-requisitos 📋
* [C++ 17](https://nuwen.net/mingw.html) 
* [Graphviz](https://graphviz.org/download/)


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
## Pruebas 


### Grafo 1  dirigido
<figure align="center" class="image">
  <img src="Graph/cmake-build-debug/graph1.png" width="70%" height="60%" style="text-align:center;">
</figure>

### Grafo 2 dirigido
<figure class="image" align="center">
  <img src="Graph/cmake-build-debug/graph2.png" width="70%" height="100%" style="text-align:center;">
</figure>

### Grafo 3 dirigido
<figure class="image" align="center">
  <img src="Graph/cmake-build-debug/graph3.png" width="70%" height="60%" style="text-align:center;">
</figure>



### Grafo 1 no dirigido
<figure align="center" class="image">
  <img src="Graph/cmake-build-debug/udgraph1.png" width="30%" height="40%" style="text-align:center;">
</figure>

### Grafo 2 no dirigido
<figure class="image" align="center">
  <img src="Graph/cmake-build-debug/udgraph2.png" width="30%" height="40%" style="text-align:center;">
</figure>

### Grafo 3 no dirigido
<figure class="image" align="center">
  <img src="Graph/cmake-build-debug/udgraph3.png" width="30%" height="40%" style="text-align:center;">
</figure>


##  Grafo no dirigido 💯

### Especificaciones de los métodos (UnDirectedGraph)

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
bool UnDirectedGraph<TV, TE>::deleteEdges(string id) {
if (this->vertexes.find(id) == this->vertexes.end())
return false;

    auto all_edges = &(this->vertexes[id])->edges;

    while (!all_edges->empty()) {
        auto get_start_vertex = (*all_edges->begin())->vertexes[0];
        auto get_goal_vertex = (*all_edges->begin())->vertexes[1];

        for (auto i = (get_goal_vertex->edges).begin(); i != (get_goal_vertex->edges).end(); i++) {
            if ((*i)->vertexes[1] == get_start_vertex) {
                (get_goal_vertex->edges).erase(i);
                E--;
                break;
            }
        }
        all_edges->pop_front();
    }
    return true;
}
```
deleteEdges se encarga de aislar un vertice para poder realizar una correcta eliminacion de datos.
Para esto primero revisa si el vértice a eliminar existe en el grafo, si es el caso, se procede a eliminar 
todas las aristas conectadas a este de forma iterativa hasta que no quede ninguna arista y retorna true.
```cpp
template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteEdge(string start, string end){

    auto all_edges = &(this->vertexes[start])->edges;
    for (auto i = all_edges->begin(); i != all_edges->end(); i++) {
        if (((*i)->vertexes[1])->id == end) {
            all_edges->erase(i);
            return true;
        }
    }

    auto all_edges1 = &(this->vertexes[end])->edges;
    for (auto i = all_edges1->begin(); i != all_edges1->end(); i++) {
        if (((*i)->vertexes[1])->id == start) {
            all_edges1->erase(i);
            return true;
        }
    }
    E--;
}
```
Similar al deleteEdges, el deleteEdge realiza la misma acción pero únicamente para una arista
específica; es decir, si la arista está conectada por la variable "start" y "end" se elimina.
Caso contrario sigue buscando entre las aristas de "start" hasta hallar una que coincida para eliminarla.
Si no existe ninguna, retornará false.

```cpp
template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::empty() {
    return this->vertexes.size() == 0;
}
```
La función empty se encarga de verificar si el grafo se encuentra vacío o cuenta con algún vértice insertado.

```cpp
template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::clear() {
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
bool UnDirectedGraph<TV, TE>::findById(string id) {
    if (this->vertexes.find(id) == this->vertexes.end()) return false;
    return true;
}
```

El findById es una función booleana que retorna verdadero en caso se encuentre
un vector con el Id solicitado; caso contrario, retorna false.


````cpp
template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::displayVertexFile(ofstream &filename, string id) {
    if (this->vertexes.find(id) == this->vertexes.end())
        return;

    auto all_edges = (this->vertexes[id])->edges;
    auto ids = id;
    for (auto i: all_edges) {
        for (auto it = this->vertexes.begin(); it != this->vertexes.end(); ++it) {
            if (it->second == (*i).vertexes[1]) ids = it->first;
        }

        filename << id <<" -- "<< ids << " [label = \""<< (*i).weight<<"\"];"<<endl;
    }
}
````
Esta función se encarga de guardar los vértices
y las aristas que se conectan a un vértice que funciona como padre del grafo que se indica en la declaración de la función
en la dirección del filename.



````cpp
template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::display_file(ofstream &filename){

    filename <<"digraph graph1{ "<<endl;
    for (auto i: this->vertexes) {
        displayVertexFile(filename, i.first);
    }
    filename <<" } ";
}
````
Lo que hace esta función es llamar iterativamente a diplayVertexFile, de esta manera,
el archivo va a contener todas las aristas del grafo y sus conexiones para poder realizar un display más adalante.


````cpp
template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::display() {
    for (auto i: this->vertexes) {
        displayVertex(i.first);
    }
}
````

La función display recorre el contenedor vertexes y por cada vértice, llama a la función displayVertex y muestra en pantalla todas las
aristas y sus respectivos vértices que estan conectados dentro del grafo.


````cpp
template<typename TV, typename TE>
float UnDirectedGraph<TV, TE>::density() {
    int V = this->vertexes.size();
    return 2 * E / ((float) V * (V - 1));
}
````
Esta función nos permite calcular la densidad del grafo siguiendo la ecuación 2 * (cantidad de aristas)/(cantidad de vertices) * (cantidad de vertices - 1)



````cpp
template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::isDense(float threshold) {
    return this->density() > threshold;
}
````
isDense verifica si la densidad del grafo es mayor threshold

````cpp
template<typename TV, typename TE>
TE &UnDirectedGraph<TV, TE>::operator()(string start, string end) {
    if (!findById(start))
        throw out_of_range("Vertex not found");
    auto par = this->vertexes[start]->edges;
    for (auto it : par) {
        if (it->vertexes[0] == this->vertexes[end] || it->vertexes[1] == this->vertexes[end]) {
            return it->weight;
        }
    }
    throw std::out_of_range("Edge not found");
}
````
Para iniciar la función, se debe comprobar si el vértice de inicio existe en el grafo, caso contrario,
se retorna el error "fuera de rango". Si el vértice existe se procede a iterar por las aristas que están conectadas
con el vértice de inicio y comprueban si el otro vértice es el "end" para poder retornar el peso de la arista.
Si no se encuentra ningún vértice que coincida con el "end", lanza un error de "Edge not found".
````cpp
template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::isStronglyConnected() throw() {
    if(this->isConnected()){return true;}
    else{return false;}
}
````
Debido a que las conexiones entre los vértices en el UnDirectedGraph son bidireccionales, desde
un vértice siempre se podrá llegar a todos los vértices dentro del grafo. Por lo tanto, la función
siempre retornará true.

````c++
template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::isConnected() {
    std::set<string> visited;
    std::stack<Vertex<TV, TE>* > pila;

    string fid = (*this->vertexes.begin()).first;
    visited.insert(fid);

    for (auto i : (*this->vertexes.begin()).second->edges) {
        Vertex<TV, TE> *ax = i->vertexes[1];
        if (visited.find(ax->id) == visited.end()) {
            pila.push(ax);
        }
    }

    while (!pila.empty()) {
        Vertex<TV, TE> *to_insert = pila.top();
        pila.pop();
        visited.insert(to_insert->id);

    for (auto i : to_insert->edges) {
        Vertex<TV, TE> *ax = i->vertexes[1];
        if (visited.find(ax->id) == visited.end()) {
            pila.push(ax);
        }
    }
}
if (visited.size() == this->vertexes.size()){return true;}
}
````

La funcion isconected tiene como objetivo, comprobar si desde el vértice solicitado
se puede llegar a todos los vertices del grafo. Par esta implementcación, implementamos
una estuctura de código similar a la del dfs, anexa las aristas anexadas al vértice de inicio
para saber a qué vértices está conectado. Luego verifica si esos vértices ya se han visitado,
si no lo han sido, se añaden a la pila y se marca como visitado hasta verificar todos los vértices.
Finalmente, si el tamaño de la pila es igual a la cantidad de vértices, retorna true.
##  Grafo dirigido 🔝

### Especificaciones de los métodos (DirectedGraph)
````cpp
template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::insertVertex(string id, TV vertex) {
    if (this->vertexes.find(id) != this->vertexes.end())
        return false;

    auto *new_vertex = new Vertex<TV, TE>;
    new_vertex->data = vertex;
    new_vertex->id = id;
    this->vertexes[id] = new_vertex;

    return true;
}
````
La función, insertVertex verifica primero si existe algún vértice con id igual al que se desea
ingresar, si es así, se añade un vértice nuevo con el peso e id solicitado.

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

````cpp
template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::deleteEdges(string id) {
    if (this->vertexes.find(id) == this->vertexes.end())
        return false;

    auto all_edges = &(this->vertexes[id])->edges;

    while (!all_edges->empty()) { // Elimino aristas hasta que la lista de adyacencia quede vacía
        E--;
        all_edges->pop_front();
    }

    return true;
}
````
El deleteEdges se encarga de eliminar todas las aristas conectadas a un vértice, para poder aislarlo y, posteriormente, eliminarlo.
Sin embargo, antes de realizar dicha acción, se debe verificar que dicho vértice que se desea aislar existe en el grafo, caso contrario, retorna que no se logró
realizar la acción.

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
void DirectedGraph<TV, TE>::displayVertexFile(ofstream &filename, string id) {
    if (this->vertexes.find(id) == this->vertexes.end())
        return;

    auto all_edges = (this->vertexes[id])->edges;
    auto ids = id;
    for (auto i: all_edges) {
        for (auto it = this->vertexes.begin(); it != this->vertexes.end(); ++it) {
            if (it->second == (*i).vertexes[1]) ids = it->first;
        }

        filename << id <<" -> "<< ids << " [label = \""<< (*i).weight<<"\"];"<<endl;
    }
}
````
Esta función se encarga de, en una dirección de archivo ingresada, guardar los vértices 
y las aristas que se conectan a un vértice que funciona como padre del grafo que se indica en la declaración de la función.

 

````cpp
template<typename TV, typename TE>
void DirectedGraph<TV, TE>::display_file(ofstream &filename){

    filename <<"digraph graph1{ "<<endl;
    for (auto i: this->vertexes) {
        displayVertexFile(filename, i.first);
    }
    filename <<" } ";
}
````
Lo que hace esta función es llamar iterativamente a la función explicada anteriormente, de esta manera,
el archivo va a contener todas las aristas del grafo y sus conexiones para poder realizar un display más adalante.


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


````cpp
template<typename TV, typename TE>
float DirectedGraph<TV, TE>::density() {
    int V = this->vertexes.size();
    return 2 * E / ((float) V * (V - 1));
}
````
Esta función nos permite calcular la densidad del grafo siguiendo la ecuación 2 * (cantidad de aristas)/(cantidad de vertices) * (cantidad de vertices - 1)


````cpp
template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::isDense(float threshold) {
    return this->density() > threshold;
}
````
isDense verifica si la densidad del grafo es mayor threshold

````cpp
template<typename TV, typename TE>
TE &DirectedGraph<TV, TE>::operator()(string start, string end) {
    if (!findById(start))
        throw out_of_range("Vertex not found");
    auto par = this->vertexes[start]->edges;
    for (auto it : par) {
        if (it->vertexes[0] == this->vertexes[end] || it->vertexes[1] == this->vertexes[end]) {
            return it->weight;
        }
    }
    throw std::out_of_range("Edge not found");
}
````
Para iniciar la función, se debe comprobar si el vértice de inicio existe en el grafo, caso contrario,
se retorna el error "fuera de rango". Si el vértice existe se procede a iterar por las aristas que están conectadas
con el vértice de inicio y comprueban si el otro vértice es el "end" para poder retornar el peso de la arista.
Si no se encuentra ningún vértice que coincida con el "end", lanza un error de "Edge not found".
````cpp
template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::isStronglyConnected() throw() {
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
        if (visited.size() != this->vertexes.size()){return false;}
    }
    return true;
}
````
Esta función de complejidad de O(n^2) se encarga de verificar vértice por vértice, todas las aristas que los conectan
con el objetivo de verificar si desde un vértice se puede llegar a recorrer todo el grafo.
Si alguno de los vértices no logra recorrer todo el grafo, retorna false. Caso contrario, el grafo puede recorrerse
completamente por cualquier vértice perteneciente a este, retorna true.

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
una estuctura de código similar a la del dfs, anexa las aristas anexadas al vértice de inicio
para saber a qué vértices está conectado. Luego verifica si esos vértices ya se han visitado,
si no lo han sido, se añaden a la pila y se marca como visitado hasta verificar todos los vértices.
Finalmente, si el tamaño de la pila es igual a la cantidad de vértices, retorna true.


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

### kruskal.h
````cpp
void minimal(){
        sort(edges.begin(), edges.end());
        int k= 0;
        for (EdgeE<TV, TE> e : edges) {
            if (Find(e.u) != Find(e.v)) {
                cost += e.weight;
                result.push_back(e);
                Union(e.u, e.v);
            }
        }
}

UnDirectedGraph<TV, TE>* apply(){
        this->minimal();
        G = new UnDirectedGraph<TV, TE>();
        for(pair<string, Vertex<TV, TE> *> vertex: aux_graph->vertexes)
            G->insertVertex(vertex.first, vertex.second->data);
        for (auto edge : result){
            string aux1 , aux2;
            int k =0;
            for(pair<string, Vertex<TV, TE> *> vertex: aux_graph->vertexes){
                if (k == edge.u)
                    aux1 = vertex.first;
                if(k == edge.v)
                    aux2 = vertex.first;
                k++;
            }
            G->createEdge(aux1, aux2, edge.weight);
        }
        return G;
}
````
En la implemtación de kruskal usamos Disjoin Sets. 
Ordenamos todas las aristas en orden creciente según sus pesos. Ponemos cada vértice en su set
llamando a MakeSet. Iteramos por todas las aristas ordenandas y por cada una de las aristas 
determinamos si el vértice de fin pertenece a un set diferente, realizando llamadas a Find(). 
Por último, realizamos Union de los sets (Union by rank). 

### bfs.h
````cpp
template<typename TV, typename TE>
class bfs{
private:
    DirectedGraph<TV,TE>* G;
public:
    bfs() = default;
    bfs(Graph<TV,TE>* &grafo, string vertexid) {
        std::unordered_set<string> visited;
        std::queue<pair<string ,Vertex<TV,TE>*>> cola;

        auto aux = grafo->vertexes[vertexid];
        G = new DirectedGraph<TV,TE>;
        G->insertVertex(vertexid, aux->data);
        visited.insert(vertexid);

        for(auto i : aux->edges){
            Vertex<TV,TE>* ax = i->vertexes[1];
            if(visited.find(ax->id) ==visited.end()){
                cola.push(make_pair( aux->id, ax));
            }
        }



        while(!cola.empty()){
            pair<string ,Vertex<TV,TE>*> res = cola.front();
            cola.pop();
            string id; Vertex<TV,TE>* to_insert;
            id = res.first;
            to_insert = res.second;

            if(visited.find(to_insert->id) ==visited.end()) {
                visited.insert(to_insert->id);
                G->insertVertex(to_insert->id, to_insert->data);
                G->createEdge(id, to_insert->id, 1);
            }

            for(auto i : to_insert->edges){
                Vertex<TV,TE>* ax = i->vertexes[1];
            if(visited.find(ax->id) ==visited.end()){
                    cola.push(make_pair(to_insert->id,ax));
                }
            }
        }
    }

    DirectedGraph<TV,TE>* apply(){
        return G;
    }

};
````
Utilizamos un unordered_set para guardar los id's de los vértices visitados, un queue que almacenará un pair que contendrá los vértices adyacentes junto al actual con el id del actual vértice, y un grafo dirigido, el cual será el nuevo grafo que se va a retornar. Durante cada iteración se verifica si existe el vértice actual en el contenedor de los vértices visitados, siendo el caso de que no exista, este se inserta en visited, el grafo y se crea una arista entre el vértice y de su adyacente. Luego, se explora e inserta los vértices adyacentes que aún no están en visited. Finalmente, con el método apply(), este retornará una grafo dirigido no ponderado. 

### dfs.h
````cpp

template<typename TV, typename TE>
class dfs{
private:
    DirectedGraph<TV,TE>* G;
public:
    dfs() = default;
    dfs(Graph<TV,TE>* &grafo, string vertexid) {
        std::unordered_set<string> visited;
        std::stack<pair<string ,Vertex<TV,TE>*>> pila;

        auto aux = grafo->vertexes[vertexid];
        G = new DirectedGraph<TV,TE>;
        G->insertVertex(vertexid, aux->data);

        visited.insert(vertexid); //PREGUNTAR AL PROFE

        for(auto& i : aux->edges){
            Vertex<TV,TE>* ax = i->vertexes[1];
            if(visited.find(ax->id) ==visited.end()){
                pila.push(make_pair( aux->id, ax));
            }
        }

        while(!pila.empty()){
            pair<string ,Vertex<TV,TE>*> res = pila.top();
            pila.pop();
            string id; Vertex<TV,TE>* to_insert;
            id = res.first;
            to_insert = res.second;

            if(visited.find(to_insert->id) ==visited.end()) {
                visited.insert(to_insert->id);
                G->insertVertex(to_insert->id, to_insert->data);
                G->createEdge(id, to_insert->id, 1);
            }

            for(auto& i : to_insert->edges){
                Vertex<TV,TE>* ax = i->vertexes[1];
                if(visited.find(ax->id) ==visited.end()){
                    pila.push(make_pair(to_insert->id,ax));
                }
            }
        }
    }

    DirectedGraph<TV,TE>* apply(){
        return G;
    }

};
````
El dfs tiene la misma estructura que el bfs; sin embargo, se distingue de este por usar un stack en lugar de queue.

###Prim
```` cpp
prim(Graph<TV,TE>* &grafo,const string& id){

        priority_queue<par, vector<par>, Compare> cont;
        unordered_set<string> visited;
        primm = new UnDirectedGraph<TV,TE>;

        primm->insertVertex(id,grafo->vertexes[id]->data);
        visited.insert(id);

        Vertex<TV,TE>* temp = grafo->vertexes[id];
        for(auto i: temp->edges){
            Vertex<TV,TE>* ax = i->vertexes[1];
            if(visited.find(ax->id) ==visited.end()){
                cont.push(make_tuple(id,i->weight,ax->id));
            }
        }

        cost =0;

        while (!cont.empty()){
            string origin = get<0>(cont.top());
            int mcost  = get<1>(cont.top());
            string idd = get<2>(cont.top());
            cont.pop();

            if(visited.find(idd) == visited.end()){
                cost += mcost;
                visited.insert(idd);
                primm->insertVertex(idd, grafo->vertexes[idd]->data);
                primm->createEdge(origin,idd, mcost);
                Vertex<TV,TE>* nuevo = grafo->vertexes[idd];

                for(auto i: nuevo->edges){
                    Vertex<TV,TE>* ax = i->vertexes[1];
                    if(visited.find(ax->id) ==visited.end()){

                        cont.push(make_tuple(idd,i->weight,ax->id));
                    }
                }
            }

        }

    }

    UnDirectedGraph<TV,TE>* apply(){
        return primm;
    }
    int mstcost(){
        return cost;
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

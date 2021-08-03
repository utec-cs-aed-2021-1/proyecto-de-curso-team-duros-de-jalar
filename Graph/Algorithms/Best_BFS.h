
#ifndef PROYECTO_DE_CURSO_TEAM_DUROS_DE_JALAR_MAIN_BEST_BFS_H
#define PROYECTO_DE_CURSO_TEAM_DUROS_DE_JALAR_MAIN_BEST_BFS_H
#include "DirectedGraph.h"
#include "UndirectedGraph.h"
template<typename TV, typename TE>
struct Compare1{
    bool operator()(const tuple<string ,TE,Vertex<TV,TE>*>& a, const tuple<string ,TE,Vertex<TV,TE>*>& b){
        if(get<1>(a) > get<1>(b)){
            return true;
        }
        return false;
    }
};


template<typename TV, typename TE>
class Best_BFS{
    DirectedGraph<TV,TE>* out;
public:
    Best_BFS(Graph<TV,TE>* grafo, const string& start){

        std::unordered_set<string> visited;
        std::priority_queue<tuple<string, TE,Vertex<TV,TE>*>, vector<tuple<string, TE, Vertex<TV,TE>*>>,Compare1<TV,TE>> cola;

        auto aux = grafo->vertexes[start];
        out = new DirectedGraph<TV,TE>;
        out->insertVertex(start, aux->data);
        visited.insert(start);

        for(auto i : aux->edges){
            Vertex<TV,TE>* ax = i->vertexes[1];
            if(visited.find(ax->id) ==visited.end()){
                cola.push(make_tuple( aux->id,i->weight ,ax));
            }
        }



        while(!cola.empty()){
            tuple<string,TE,Vertex<TV,TE>*> res = cola.top();
            cola.pop();
            string id; Vertex<TV,TE>* to_insert;
            id = get<0>(res);
            TE cost = get<1>(res);
            to_insert = get<2>(res);

            if(visited.find(to_insert->id) ==visited.end()) {
                visited.insert(to_insert->id);
                out->insertVertex(to_insert->id, to_insert->data);
                out->createEdge(id, to_insert->id, cost);
            }


            for(auto i : to_insert->edges){
                Vertex<TV,TE>* ax = i->vertexes[1];
                if(visited.find(ax->id) ==visited.end()){
                    cola.push(make_tuple(to_insert->id,i->weight,ax));
                }
            }
        }

    }
    Best_BFS(DirectedGraph<TV,TE>* grafo, const string& start){

        std::unordered_set<string> visited;
        std::priority_queue<tuple<string, TE,Vertex<TV,TE>*>, vector<tuple<string, TE, Vertex<TV,TE>*>>,Compare1<TV,TE>> cola;

        auto aux = grafo->vertexes[start];
        out = new DirectedGraph<TV,TE>;
        out->insertVertex(start, aux->data);
        visited.insert(start);

        for(auto i : aux->edges){
            Vertex<TV,TE>* ax = i->vertexes[1];
            if(visited.find(ax->id) ==visited.end()){
                cola.push(make_tuple( aux->id,i->weight ,ax));
            }
        }



        while(!cola.empty()){
            tuple<string,TE,Vertex<TV,TE>*> res = cola.top();
            cola.pop();
            string id; Vertex<TV,TE>* to_insert;
            id = get<0>(res);
            TE cost = get<1>(res);
            to_insert = get<2>(res);

            if(visited.find(to_insert->id) ==visited.end()) {
                visited.insert(to_insert->id);
                out->insertVertex(to_insert->id, to_insert->data);
                out->createEdge(id, to_insert->id, cost);
            }


            for(auto i : to_insert->edges){
                Vertex<TV,TE>* ax = i->vertexes[1];
                if(visited.find(ax->id) ==visited.end()){
                    cola.push(make_tuple(to_insert->id,i->weight,ax));
                }
            }
        }

    }
    Best_BFS(UnDirectedGraph<TV,TE>* grafo, const string& start){

        std::unordered_set<string> visited;
        std::priority_queue<tuple<string, TE,Vertex<TV,TE>*>, vector<tuple<string, TE, Vertex<TV,TE>*>>,Compare1<TV,TE>> cola;

        auto aux = grafo->vertexes[start];
        out = new DirectedGraph<TV,TE>;
        out->insertVertex(start, aux->data);
        visited.insert(start);

        for(auto i : aux->edges){
            Vertex<TV,TE>* ax = i->vertexes[1];
            if(visited.find(ax->id) ==visited.end()){
                cola.push(make_tuple( aux->id,i->weight ,ax));
            }
        }



        while(!cola.empty()){
            tuple<string,TE,Vertex<TV,TE>*> res = cola.top();
            cola.pop();
            string id; Vertex<TV,TE>* to_insert;
            id = get<0>(res);
            TE cost = get<1>(res);
            to_insert = get<2>(res);

            if(visited.find(to_insert->id) ==visited.end()) {
                visited.insert(to_insert->id);
                out->insertVertex(to_insert->id, to_insert->data);
                out->createEdge(id, to_insert->id, cost);
            }


            for(auto i : to_insert->edges){
                Vertex<TV,TE>* ax = i->vertexes[1];
                if(visited.find(ax->id) ==visited.end()){
                    cola.push(make_tuple(to_insert->id,i->weight,ax));
                }
            }
        }

    }
    DirectedGraph<TV,TE>* apply(){
        return out;
    }
};
#endif //PROYECTO_DE_CURSO_TEAM_DUROS_DE_JALAR_MAIN_BEST_BFS_H

#ifndef PROYECTO_DE_CURSO_TEAM_DUROS_DE_JALAR_MAIN_ASTAR_H
#define PROYECTO_DE_CURSO_TEAM_DUROS_DE_JALAR_MAIN_ASTAR_H
#include "DirectedGraph.h"
#include "UndirectedGraph.h"
#include "map"
template<typename TV, typename TE>
struct comparator{
    bool operator()(const pair<Vertex<TV,TE>*,TE>& a, const pair<Vertex<TV,TE>*,TE>& b){
        if(a.second > b.second){
            return true;
        }
        return false;
    }
};

template<typename TV,typename TE>
class astar{
private:
    map<string, string> cameFrom;
    deque<string> path;
    UnDirectedGraph<TV,TE>* result;
public:
    explicit astar(Graph<TV,TE>* inpgr, string start, string goal, unordered_map<string,TE> heuristic){
        priority_queue<pair<Vertex<TV,TE>*, TE>,vector<pair<Vertex<TV,TE>*,TE>>, comparator<TV,TE>> openSet;
        unordered_set<string> openSet1;
        unordered_set<string> closedSet;


        map<string, TE> gscore;
        gscore[start] = 0;
        map<string, TE> fscore;
        fscore[start] = heuristic[start];

        openSet.push(make_pair(inpgr->vertexes[start],fscore[start]));
        while (!openSet.empty()){
            Vertex<TV,TE>* current = openSet.top().first;
            openSet.pop();
            if(current->id == goal){
                cout<<current->id<<" "<<gscore[current->id]<<" "<<fscore[current->id]<<endl;
                construct_path(current->id,inpgr,start);
                return;
            }
            closedSet.insert(current->id);
            for(auto i = current->edges.begin(); i != current->edges.end(); i++ ){
                string ax = (*i)->vertexes[1]->id;
                if(closedSet.find(ax) != closedSet.end()){
                    continue;
                }
                TE tentative_gscore = gscore[current->id]  +  (*i)->weight;

                if(openSet1.find(ax) == openSet1.end()) {
                    cameFrom[ax] = current->id;
                    gscore[ax] = tentative_gscore;
                    fscore[ax] = tentative_gscore + heuristic[ax];
                    openSet.push(make_pair((*i)->vertexes[1],fscore[ax]));
                    openSet1.insert(ax);
                    continue;
                }

                if(tentative_gscore>=gscore[(*i)->vertexes[1]->id]){continue;}

                cameFrom[ax] = current->id;
                gscore[ax] = tentative_gscore;
                fscore[ax] = tentative_gscore + heuristic[(*i)->vertexes[1]->id];
            }
        }
    }
    void construct_path(string current, Graph<TV,TE>* inpgr, const string& start){
        path.push_front(current);
        result = new UnDirectedGraph<TV,TE>;
        while (cameFrom.find(current) != cameFrom.end() && current!=start){

            Vertex<TV,TE>* n1 = inpgr->vertexes[current];

            result->insertVertex(n1->id,n1->data);

            current = cameFrom[current];

            Vertex<TV,TE>* n2 = inpgr->vertexes[current];
            result->insertVertex(n2->id,n2->data);
            TE W=0;
            for(auto i = n1->edges.begin(); i!=n1->edges.end();i++){
                if(current == (*i)->vertexes[1]->id){
                    W = (*i)->weight;
                }
            }
            result->createEdge(n1->id,n2->id,W);
            cout<<n1->id<<" "<<n2->id<<endl;

            path.push_front(current);
        }
    }

    void display(){
        for(auto & i : path){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    UnDirectedGraph<TV,TE>* apply(){
        return result;
    }

};



#endif

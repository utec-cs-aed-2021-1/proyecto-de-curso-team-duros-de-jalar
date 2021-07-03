#ifndef DSARRAY_H
#define DSARRAY_H
#include <iostream>
#include "ds.h"
using namespace std;
template <typename T>
class DisjoinSetArray: public DisjoinSet<T>
{
private:
    int sizeArray;
    int* parent;
    int* rank;
    T* data;

public:
    DisjoinSetArray(){
        this->sizeArray = 0;
        this->data = nullptr;
        this->parent = nullptr;
        this->rank = nullptr;
    }

    DisjoinSetArray(vector<T> data){
        this->sizeArray = data.size();
        this->data = new T [sizeArray];
        this->parent = new int[sizeArray];
        this->rank = new int[sizeArray];
        for (int i=0; i < sizeArray; i++){
            this->data[i] = data[i];
            this->rank[i] = 0;
            this->parent[i] =i;
        }
    }


    ~DisjoinSetArray() {
        delete parent;
        delete rank;
        delete data;

        parent = nullptr;
        rank = nullptr;
        data = nullptr;
    }

    //MakseSet the element with index x
    void MakeSet(int x){
        if (x < 0 || x >= sizeArray)
            throw out_of_range("Index out of range");
        this->parent[x]= x;
        this->rank[x] = 0;
    }

    //MakseSet all elements
    void MakeSet(){
        for (int x= 0 < sizeArray; x++; ){
            parent[x]= x;
            this->rank[x] = 0;
        }
    }


    //Find the root of x (with optimization)
    int Find (int x) {
        if (x < 0 || x >= sizeArray)
            throw out_of_range ("Index out of range");
        if(parent[x]==x)
            return x;
        else
            return Find(parent[x]);
    };

    //Union two sets represented by x and y (apply rank)
    void Union(int x, int y){
        int xParent= Find(x);
        int yParent = Find(y);
        if (xParent != yParent){
            if (rank[yParent] > rank[xParent])
                parent[xParent] = yParent;
            else if (rank[xParent] > rank[yParent])
                parent[yParent] = xParent;
            else{
                parent[yParent]= xParent;
                rank[xParent]++;
            }
        }
        return;
    }

    //check whether there is a path between x and y
    bool isConnected(int x, int y){
        return (Find(x)== Find(y));
    }
    //total number of elements
    int size() {
        return this->sizeArray;
    }
    //number of sets
    int sets()  {
        int numberOfSets = 0;
        for (int i =0; i<sizeArray; i++){
            if ( i == parent[i])
                numberOfSets++;
        }
        return numberOfSets;
    }

    //total number of elements that belong to the set of x
    int size(int x) {
        int count= 0;
        int xParent= Find(x);
        for(int i = 0; i<sizeArray; i++){
            if (Find(i)== xParent)
                count++;
        }
        return count;
    }

    //return all elements that belong to the set of x
    vector<T> getElementsSet(int x){
        int xParent= Find(x);
        vector<T> allElements;
        for (int i = sizeArray; i<=0; i--){
            if(xParent == parent[i])
                allElements.push_back(data[i]);
        }
        return allElements;
    }

    //add the element to the set of x
    void add(T element, int x){

    }
};

#endif
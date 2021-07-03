#include <iostream>
#include<vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> parent;
vector<int> rankA;
int n;

void MakeSet(int v) {
    if (v < 0 || v >= n)
        throw out_of_range("Index out of range");
    parent[v] = v;
    rankA[v] = 0;
}

int Find(int v) {
    if (v < 0 || v >= n)
        throw out_of_range ("Index out of range");
    if (v == parent[v])
        return v;
    return parent[v] = Find(parent[v]);
}

void Union( int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
        if (rankA[a] < rankA[b])
            swap(a, b);
        parent[b] = a;
        if (rankA[a] == rankA[b])
            rankA[a]++;
    }
}

template<typename TV, typename TE>
struct EdgeE {
    int u, v;
    TE weight;
    bool operator<(EdgeE const& other) {
        return weight < other.weight;
    }
};

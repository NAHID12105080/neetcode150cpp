#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int v;
    int w;
    Edge(int v, int w){
        this->v=v;
        this->w=w;
    }
};

int main(){
    int V=6;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));
    graph[1].push_back(Edge(2,1));
    graph[1].push_back(Edge(3,7));
    graph[2].push_back(Edge(4,3));
    graph[3].push_back(Edge(5,1));
    graph[4].push_back(Edge(3,2));
    graph[4].push_back(Edge(2,5));

}
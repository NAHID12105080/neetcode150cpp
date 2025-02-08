#include <iostream>
#include<vector>
#include<list>
#include<queue>
#include<string>
using namespace std;

class Graph{
    int V;
    list<int>*l;
    public:
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int u=0;u<V;u++){
            list<int> neighbors= l[u];
            cout<< u<<":-> ";
            for(int v:neighbors){
                cout<<v<<" ";
            }
            cout<<endl;
        }

    }

    bool undirCycleHelper(int u, vector<bool>&visited, int parent){
        visited[u]=true;
        list<int>neighbors=l[u];
        for(int v:neighbors){
            if(!visited[v]){
                if(undirCycleHelper(v,visited,u)){
                    return true;
                }
            }
            else if(v!=parent){
                return true;
            }
        }
        return false;
    }

    bool undirCycle(){
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(undirCycleHelper(i,visited,-1)){
                    return true;
                }
            }
        }
        return false;
    }

    

};

int main(){
    Graph graph(5);
    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    graph.addEdge(2,4);

    graph.print();
    cout<<graph.undirCycle()<<endl;
  
    return 0;
}
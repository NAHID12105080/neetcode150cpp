#include <iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<string>
using namespace std;

class Graph{
    int V;
    list<int>*l;
    bool isUndir;
    public:
    Graph(int V,bool isUndir){
        this->V=V;
        l=new list<int>[V];
        this->isUndir=isUndir;
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        if(isUndir) l[v].push_back(u);
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

void calcIndegree(vector<int>&indegree){
    for(int i=0;i<V;i++){
        list<int>neighbors=l[i];
        for(int v:neighbors){
            indegree[v]++;
        }
    }
}

void khanTopoSort(){
    vector<int>indegree(V,0);
    calcIndegree(indegree);
    queue<int>q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        list<int>neighbors=l[u];
        for(int v:neighbors){
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }
    cout<<endl;
}

};


int main(){
    Graph graph(4,false);
    graph.addEdge(1,0);
    graph.addEdge(0,2);
    graph.addEdge(2,3);
    graph.addEdge(3,0);
    graph.print();
    graph.khanTopoSort();

  return 0;
}
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

    void toposortHelper(int u, vector<bool>&vis, stack<int>&s){
        vis[u]=true;
        list<int>neighbors=l[u];
        for(int v:neighbors){
            if(!vis[v]){
                toposortHelper(v,vis,s);
            }
        }
        s.push(u);
    }

    void topoSortUsingStack(){
        vector<bool>vis(V,false);
        stack<int>s;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                toposortHelper(i,vis,s);
            }
        }

        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
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
 
  
    return 0;
}
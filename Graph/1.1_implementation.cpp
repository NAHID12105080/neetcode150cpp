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

    void bfsHelper(int start, vector<bool>&visisted){
        queue<int>q;
        q.push(start);
        visisted[start]=true;

        while (q.size()>0)
        {
            int u=q.front();
            q.pop();
            cout<<u<<" ";

            list<int>neighbors=l[u];
            for(auto v:neighbors){
                if(!visisted[v]){
                    visisted[v]=true;
                    q.push(v);
                }
            }
            /* code */
        }
    cout<<endl;
    }

    void bfs(){
        vector<bool>visisted(V,false);
        for(int i=0;i<V;i++){
            if(!visisted[i]){
                bfsHelper(i,visisted);
                cout<<endl;
            }

        }
    }

    void dfsHelper(int u, vector<bool> &vis){
        vis[u]=true;
        cout<<u<<" ";

        list<int> neighbors=l[u];
        for(int v:neighbors){
            if(!vis[v]){
                dfsHelper(v,vis);
            }
        }
    }

    void dfs(){
        vector<bool> vis(7,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsHelper(i,vis);
            }
        }
        cout<<endl;
    }

    bool pathHelper(int src,int desti,vector<bool>&vis){
        if(src==desti){
            return true;
        }

        vis[src]=true;
        list<int>neighbors=l[src];

        for(int v:neighbors){
            if(!vis[v]){
                if(pathHelper(v,desti,vis)){
                    return true;
                }
            }
        }


    }    

    bool hasPath(int src,int desti){
        vector<bool>vis(V,false);
        return pathHelper(src,desti,vis);
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
    graph.bfs();
    graph.dfs();
    cout<< graph.hasPath(0,2);
    return 0;
}
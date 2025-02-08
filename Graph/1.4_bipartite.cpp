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

    bool isBipartite(){
        queue<int>q;
        vector<int>color(V,-1);
        vector<bool>visited(V,false);

        for(int i=0;i<V;i++){
            if(!visited[i]){
                q.push(i);
                color[i]=0;
                visited[i]=true;

                while(q.size()>0){
                    int u=q.front();
                    q.pop();
                    list<int>neighbors=l[u];
                    for(int v:neighbors){
                        if(color[v]==-1){
                            color[v]=1-color[u];
                            q.push(v);
                            visited[v]=true;
                        }
                        else if(color[v]==color[u]){
                            return false;
                        }
                    }
                }
            }
        }
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
    
    if(graph.isBipartite()){
        cout<<"Yes, it is Bipartite"<<endl;
    }
    else{
        cout<<"No, it is not Bipartite"<<endl;
    }
  
    return 0;
}
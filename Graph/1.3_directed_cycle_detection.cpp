#include <iostream>
#include<vector>
#include<list>
#include<queue>
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

    bool isCycleDirHelper(int u, vector<bool>&visited, vector<bool>&recPath){
            visited[u]=true;
            recPath[u]=true;
    
            list<int>neighbors=l[u];
            for(int v:neighbors){
                if(!visited[v]){
                    if(isCycleDirHelper(v,visited,recPath)){
                        return true;
                    }
                }
                else if(recPath[v]){
                    return true;
                }
            }
            recPath[u]=false;
            return false;
    }  

   bool isCycleDir(){
    vector<bool>visited(V,false);
    vector<bool> recPath(V,false);

    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(isCycleDirHelper(i,visited,recPath)){
                return true;
            }
        }
    }

    return false;
   }

    void printAllPathsHelper(int src,int dest,vector<bool>&visited,string &path){
         if(src==dest){
              cout<<path<<dest<<endl;
              return;
         }
         visited[src]=true;
         path+=to_string(src)+" ";//convert to string otherwise will add ascii value
         
         list<int>neighbors=l[src];
         for(int v:neighbors){
              if(!visited[v]){
                printAllPathsHelper(v,dest,visited,path);
              }
         }
         //on backtracking(when we reach the end of the path) we need to remove the last node from the path
         path=path.substr(0,path.size()-1);
         visited[src]=false;
    }
  
  void printAllPaths(int src,int dest){
    vector<bool>visited(V,false);
    string path="";
    printAllPathsHelper(src,dest,visited,path);
  }
};

int main(){
    Graph graph(6,false);
    graph.addEdge(0,3);
    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.addEdge(4,0);
    graph.addEdge(4,1);
    graph.addEdge(5,0);
    graph.addEdge(5,2);

    cout<<graph.isCycleDir()<<endl;
    graph.printAllPaths(5,1);
    
    return 0;
}
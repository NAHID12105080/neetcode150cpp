#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> max(n,vector<int>(m)),
                         alloc(n,vector<int>(m)),
                         need(n,vector<int>(m));
    vector<int> avail(m);

    for(auto &r:max) for(int &x:r) cin>>x;
    for(auto &r:alloc) for(int &x:r) cin>>x;
    for(int &x:avail) cin>>x;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            need[i][j]=max[i][j]-alloc[i][j];

    vector<bool> finish(n,false);
    for(int c=0;c<n;c++)
        for(int i=0;i<n;i++)
            if(!finish[i] &&
               equal(need[i].begin(),need[i].end(),avail.begin(),
               [](int a,int b){return a<=b;})){
                for(int j=0;j<m;j++) avail[j]+=alloc[i][j];
                finish[i]=true;
            }

    cout<<(all_of(finish.begin(),finish.end(),[](bool x){return x;})
          ?"Safe":"Not Safe");
}

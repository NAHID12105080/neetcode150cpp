#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;
    vector<unordered_map<int,int>> freq;

    DSU(int n){
        parent.resize(n+1);
        sz.resize(n+1,1);
        freq.resize(n+1);
        for(int i=1;i<=n;i++) parent[i]=i;
    }

    int find(int x){
        return parent[x]==x ? x : parent[x]=find(parent[x]);
    }

    void unite(int a,int b, vector<int>& total, vector<int>& ans, int time){
        a=find(a);
        b=find(b);
        if(a==b) return;

        if(sz[a] < sz[b]) swap(a,b);

        parent[b]=a;
        sz[a]+=sz[b];

        for(auto &it : freq[b]){
            int g = it.first;
            int cnt = it.second;

            freq[a][g]+=cnt;

            if(freq[a][g]==total[g] && ans[g]==-1)
                ans[g]=time;
        }
    }
};

int main(){
    int N,M,Q;
    cin>>N>>M>>Q;

    vector<int> game(N+1);
    vector<int> total(M+1,0);

    for(int i=1;i<=N;i++){
        cin>>game[i];
        total[game[i]]++;
    }

    vector<int> ans(M+1,-1);

    DSU dsu(N);

    for(int i=1;i<=N;i++){
        dsu.freq[i][game[i]]=1;
        if(total[game[i]]==1) ans[game[i]]=0;
    }

    for(int t=1;t<=Q;t++){
        int u,v;
        cin>>u>>v;
        dsu.unite(u,v,total,ans,t);
    }

    for(int i=1;i<=M;i++)
        cout<<ans[i]<<"\n";
}
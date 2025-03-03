#include<iostream>
#include<vector>
#include<cassert>
using namespace std;
int N;
vector<int>G[2<<17];
int ans;

pair<int,int>dfs(int u,int p)
{
	int mx1=-1e9,mx2=-1e9;
	for(int v:G[u])if(v!=p)
	{
		auto q=dfs(v,u);
		ans=max(ans,(int)G[u].size()+q.first-2);
		ans=max(ans,(int)G[u].size()+q.second-1);
		int t=max(q.first,q.second);
		if(mx1<t)mx2=mx1,mx1=t;
		else if(mx2<t)mx2=t;
		ans=max(ans,mx1+mx2-1);
	}
	return make_pair((int)G[u].size(),mx1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)G[i].clear();
		for(int i=1;i<N;i++)
		{
			int u,v;cin>>u>>v;
			u--,v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		ans=0;
		dfs(0,-1);
		cout<<ans<<"\n";
	}
}


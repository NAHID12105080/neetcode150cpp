#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;
int N,K;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N>>K;
		vector<pair<int,int> >Ai(N);
		for(int i=0;i<N;i++)
		{
			int a;cin>>a;
			a%=K;
			if(a==0)a=K;
			Ai[i]=make_pair(-a,i);
		}
		sort(Ai.begin(),Ai.end());
		for(int i=0;i<N;i++)cout<<Ai[i].second+1<<(i+1==N?"\n":" ");
	}
}

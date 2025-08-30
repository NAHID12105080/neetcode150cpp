#include<iostream>
using namespace std;
int L[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;
		string S;
		cin>>N>>S;
		L[0]=0;
		for(int i=0;i<N;i++)
		{
			L[i+1]=L[i];
			L[i+1]|=1<<S[i]-'a';
		}
		int R=0;
		int ans=__builtin_popcount(L[N]);
		for(int i=N;i--;)
		{
			R|=1<<S[i]-'a';
			ans=max(ans,__builtin_popcount(L[i])+__builtin_popcount(R));
		}
		cout<<ans<<"\n";
	}
}

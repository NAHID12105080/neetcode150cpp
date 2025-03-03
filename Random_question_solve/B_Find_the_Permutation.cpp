#include<iostream>
#include<cassert>
using namespace std;
int N,P[1010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)P[i]=-1;
		for(int i=1;i<=N;i++)
		{
			string G;cin>>G;
			int idx=0;
			for(int j=1;j<=N;j++)if(i!=j)
			{
				if(i<j)
				{
					if(G[j-1]=='0')idx++;
				}
				else
				{
					if(G[j-1]=='1')idx++;
				}
			}
			// assert(P[idx]==-1);
			P[idx]=i;
		}
		for(int i=0;i<N;i++)cout<<P[i]<<(i+1==N?"\n":" ");
	}
}

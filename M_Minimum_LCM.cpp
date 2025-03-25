#include<iostream>
#include<cassert>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		int A=1;
		for(int i=2;i*i<=N;i++)if(N%i==0)
		{
			A=N/i;
			break;
		}
		cout<<A<<" "<<N-A<<"\n";
	}
}
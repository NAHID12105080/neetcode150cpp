#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int l,r;cin>>l>>r;
		int ans=r-l;
		if(l==1&&r==1)ans++;
		cout<<ans<<"\n";
	}
}

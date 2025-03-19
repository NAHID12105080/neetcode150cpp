#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inv2=5e8+4,mod=1e9+7;
signed main(){
	int T;
	cin>>T;
	while(T--){
		int n,ans=0;
		string s;
		cin>>n>>s;
		s=" "+s;
		for(int i=n;i>1;i--)
        { 
        ans=(ans+(s[i]=='1'))*inv2%mod;
        }
		cout<<(n-1+ans)%mod<<endl;
	}
	return 0;
}
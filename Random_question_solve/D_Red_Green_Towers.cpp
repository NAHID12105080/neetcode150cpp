#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
const int MOD=1e9+7;
 
int r,g;
int dp[N]={0};
int h;
int main(){
	cin>>r>>g;
	h=sqrt( (r+g)*2 );
	if( h*(h+1)/2>(r+g) ) h--;
	dp[0]=1;
	for(int i=1;i<=h;i++){
		for(int j=r;j>=i;j--){
			dp[j]=(dp[j]+dp[j-i])%MOD;
		}
	}
	int ans=0;
	for(int i=max(h*(h+1)/2-g,0);i<=r;i++){
		ans=(ans+dp[i])%MOD;
	}
	cout<<ans<<endl;
	return 0;
}
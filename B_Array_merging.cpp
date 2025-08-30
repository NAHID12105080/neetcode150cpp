#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,now=0,x,ans=0,len=1;
        cin>>n;
        int a[2*n+5]={0};
		for(int i=0;i<n;i++){cin>>x;if(x==now)len++;else len=1;now=x;a[x]=max(a[x],len);}
		now=0;len=1;
		for(int i=0;i<n;i++){cin>>x;if(x==now)len++;else len=1;now=x;ans=max(ans,a[x]+len);}
		for(int i=1;i<=2*n;i++){ans=max(ans,a[i]);}
		cout<<ans<<endl;
    }
}
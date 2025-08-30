#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long ans,n,m,t,x[N],r;
map<long long,long long> ma;
int main() {
	scanf("%lld",&t);
	while(t--) {
		ans=0;
		scanf("%lld%lld",&n,&m);
		ma.clear();
		for(int i=0;i<n;i++) scanf("%lld",&x[i]);
		for(int i=0;i<n;i++) {
			scanf("%lld",&r);
			for(long long j=-r;j<=r;j++)
				ma[x[i]+j]=max(ma[x[i]+j],(long long)sqrt(r*r-j*j));
		}
		for(auto i:ma) {
			ans+=i.second*2+1;
		}
		printf("%lld\n",ans);
	}
}
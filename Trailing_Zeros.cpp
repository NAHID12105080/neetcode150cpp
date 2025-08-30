#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9+7;
const int INF = LONG_MAX >> 1;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    int ans=0;
    for(int i=5;i<=n;i*=5) {
        ans += n/i;
    }
    cout<<ans<<endl;
    
}
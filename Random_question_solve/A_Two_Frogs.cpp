#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9+7;
const int INF = LONG_MAX >> 1;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc;
    cin >> tc;
    while (tc--) 
    {    
      int n,a,b;
      cin>>n>>a>>b;
      if((a^b)&1) cout<<"NO"<<endl;//checking different parity
      else cout<<"YES"<<endl;
    }
}
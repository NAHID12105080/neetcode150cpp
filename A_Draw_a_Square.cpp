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
      int l,r,d,u;
      cin>>l>>r>>d>>u;
      (l == r && r == d && d == u)?cout<<"Yes"<<endl:cout<<"No"<<endl;    
    }
}
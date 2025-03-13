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
      int n,x;
      cin>>n>>x;
      int a[n];
      for(int i=0;i<n;i++)
      {
        cin>>a[i];
      }
     int sum=accumulate(a,a+n,0);  
     (sum==n*x)?cout<<"YES"<<endl:cout<<"NO"<<endl;  
    }
}
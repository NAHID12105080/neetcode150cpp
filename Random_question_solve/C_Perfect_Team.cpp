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
      int c,m,x;
      cin>>c>>m>>x;
      int low=0,high=min(c,m),ans=0;
      while(low<=high){
            int mid=low-(low-high)/2;
            if(c+m+x-2*mid>=mid){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
      }
      cout<<ans<<endl;

    }
}
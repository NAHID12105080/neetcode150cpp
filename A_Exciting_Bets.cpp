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
        int a,b,r;
        cin>>a>>b;
        r=abs(a-b);
        if(r!=0) a=max(a,b)%r;
        cout<<r<<' '<<min(a,(r==0?0:r-a))<<endl;    
    }
}
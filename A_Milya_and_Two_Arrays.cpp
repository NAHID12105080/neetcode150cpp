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
        int n; cin>>n;
        set<int> A,B;

        for(int i=0;i<n;i++){
            int a;cin>>a;A.insert(a);
        } 
        for(int i=0;i<n;i++){
            int a;cin>>a;B.insert(a);
        }  

        if(A.size()+B.size()>3) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
}
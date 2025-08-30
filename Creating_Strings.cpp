#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9+7;
const int INF = LONG_MAX >> 1;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    vector<string> v;
    v.push_back(s);
   while(next_permutation(s.begin(),s.end())){
    v.push_back(s);
   }
    cout<<v.size()<<endl;
    for(auto x:v)
    {
        cout<<x<<endl;
    }

}
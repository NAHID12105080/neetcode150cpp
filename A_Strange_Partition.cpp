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
        int n, m; cin >> n >> m;
        int mn = 0, mx = 0;
        while (n--) {
            int x; cin >> x;
            mn += x;
            mx += (x + m - 1) / m;
            // mx += ceil(x *1.0 / m); // ceil() is a function in C++ which is used to round off any number to its nearest integer value, in other words it returns the smallest integer which is greater than or equal to the given number.

        }
        mn = (mn + m - 1) / m;
        cout << mn << " " << mx << endl;    
    }
}
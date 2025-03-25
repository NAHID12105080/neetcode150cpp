#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc;
    cin >> tc;
    while (tc--) {    
        int x, y, a;
        cin >> x >> y >> a;
        
        int r = a / (x + y);
        int sum = r * (x + y);
        
   
        sum += x;
        if (sum > a) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}

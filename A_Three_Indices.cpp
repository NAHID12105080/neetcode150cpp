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
        int n, j = 0, a[1005];
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 1; i < n - 1; i++) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                j = i;
            }
        }
        if (j) {
            cout << "YES\n" << j << " " << j + 1 << " " << j + 2 << '\n';
        } else {
            cout << "NO\n";
        }    
    }
}
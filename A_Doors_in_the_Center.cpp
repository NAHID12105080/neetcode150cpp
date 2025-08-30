#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9+7;
const int INF = LONG_MAX >> 1;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    if (n & 1) { // if n is odd
        for (int i = 0; i < n / 2; i++) {
            cout << "-";
        }
        cout << "=";
        for (int i = 0; i < n / 2; i++) {
            cout << "-";
        }
    } else { 
        for (int i = 0; i < n / 2-1; i++) {
            cout << "-";
        }
        cout << "==";
        for (int i = 0; i < n / 2-1; i++) {
            cout << "-";
        }
    }
    cout << endl;
}

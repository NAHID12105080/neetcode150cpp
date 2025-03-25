#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    while (tc--) {    
        int n, m; cin >> n >> m;
        vector<string> g(n);
        for (auto &row : g) cin >> row;

        bool flag = true;
        for (int i = 0; i < n && flag; i++) {
            for (int j = 0; j < m && flag; j++) {
                if (g[i][j] == '1') {
                    bool rowZero = false, colZero = false;
                    for (int k = 0; k < j; k++) if (g[i][k] == '0') rowZero = true;
                    for (int k = 0; k < i; k++) if (g[k][j] == '0') colZero = true;
                    if (rowZero && colZero) flag = false;
                }
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}

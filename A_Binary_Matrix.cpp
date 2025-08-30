#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LONG_MAX >> 1;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc;
    cin >> tc;
    while (tc--) {    
        int n, m;
        cin >> n >> m;
        
        vector<string> mat(n);
        for (int i = 0; i < n; ++i) cin >> mat[i];

        if (n == 1) {
            cout << count(mat[0].begin(), mat[0].end(), '1') << endl;
            continue;
        }

        if (m == 1) {
            int colOne = 0;
            for (int i = 0; i < n; ++i) colOne += (mat[i][0] == '1');
            cout << colOne << endl;
            continue;
        }

        vector<int> rowXor(n, 0), colXor(m, 0);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                rowXor[i] ^= (mat[i][j] - '0');
                colXor[j] ^= (mat[i][j] - '0');
            }

        int rowChanges = accumulate(rowXor.begin(), rowXor.end(), 0LL);
        int colChanges = accumulate(colXor.begin(), colXor.end(), 0LL);
        
        cout << max(rowChanges, colChanges) << endl;
    }
}

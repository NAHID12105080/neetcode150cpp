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
        int m, k;
        cin >> m >> k;
        vector<char> s(m);
        
        int count_S = 0;
        for (int i = 0; i < m; ++i) {
            cin >> s[i];
            if (s[i] == 'S') count_S++;
        }

        if (count_S >= k) {
            cout << m << endl;
        } else {
            cout << (k - count_S) << endl; 
        }
    }
}

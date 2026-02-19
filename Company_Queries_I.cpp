#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long


const int MAXN = 200005;
const int LOG = 30;   // because 2^29 > 5e8, safe for n <= 2e5 // taking 20 will also work

int up[MAXN][LOG];    // up[node][j] = 2^j-th ancestor of node

// Returns the k-th ancestor of node
int kthAncestor(int node, int k) {
    // Jump from LSB to MSB
    for (int bit = 0; bit < LOG; bit++) {
        if (k & (1 << bit)) {
            if (node != -1)
                node = up[node][bit];
        }
    }
    return node;
}

void solve() {
    int n, q;
    cin >> n >> q;

    // Initialize everything with -1
    memset(up, -1, sizeof(up));

    // Input: parent of nodes 2 to n
    for (int i = 2; i <= n; i++) {
        cin >> up[i][0];   // direct parent (2^0-th ancestor)
    }

    // Preprocessing: fill binary lifting table
    for (int j = 1; j < LOG; j++) {
        for (int node = 1; node <= n; node++) {
            if (up[node][j - 1] != -1)
                up[node][j] = up[ up[node][j - 1] ][j - 1];
        }
    }

    // Process queries
    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << kthAncestor(x, k) << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

class TreeCutter {
    int n, k;
    vector<vector<int>> adj;
    int treeSz;
    int cuts;

    int dfs(int node, int parent) {
        int sz = 1;
        for (int nxt : adj[node]) {
            if (nxt != parent)
                sz += dfs(nxt, node);
        }

        if (sz >= treeSz) {
            cuts++;
            return 0;
        }
        return sz;
    }

public:
    TreeCutter(int n, int k) : n(n), k(k) {
        adj.assign(n + 1, {});
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool canCut(int ts) {
        treeSz = ts;
        cuts = 0;
        dfs(1, 0);
        return cuts > k;
    }

    int solve() {
        int left = 1, right = n, ans = 0;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (canCut(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;

        TreeCutter solver(n, k);

        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            solver.addEdge(x, y);
        }

        cout << solver.solve() << "\n";
    }
}

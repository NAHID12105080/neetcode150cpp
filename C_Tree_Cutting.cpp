#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> adj(n + 1);

        for (int i = 1; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int left = 1, right = n, answer = 0;

        auto ok = [&](int treeSz) -> bool
        {
            int cuts = 0;

            auto dfs = [&]( auto &self, int node, int parent) -> int
            {
                int sz = 1;
                for (int i : adj[node])
                {
                    if (i != parent)
                        sz += self(self, i, node);
                }

                if (sz >= treeSz)
                {
                    cuts++;
                    return 0;
                }
                return sz;
            };

            dfs(dfs, 1, 1);

            return cuts > k;
        };

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (ok(mid))
                answer = mid, left = mid + 1;
            else
                right = mid - 1;
        }

        cout << answer << "\n";
    }
}

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1 << 20;
int n, k;
int subtree_size[MAX], value[MAX];
vector<int> adj[MAX];

void dfs(int node, int parent, int depth = 0)
{
    subtree_size[node] = 1;
    for (int neighbor : adj[node])
    {
        if (neighbor == parent)
            continue;
        dfs(neighbor, node, depth + 1);
        subtree_size[node] += subtree_size[neighbor];
    }
    value[node - 1] = depth - subtree_size[node] + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    nth_element(value, value + n - k, value + n);
    cout << accumulate(value + n - k, value + n, 0LL) << '\n';

    return 0;
}

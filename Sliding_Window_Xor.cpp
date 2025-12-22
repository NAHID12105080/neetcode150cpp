#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    int x, a, b, c;
    cin >> x >> a >> b >> c;

    arr[0] = x;

   
    for (int i = 1; i < n; i++) {
        arr[i] = (arr[i - 1] * a + b) % c;
    }

    // Prefix sum
    vector<int> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] ^ arr[i];//just change the previous solution with + to ^
    }

    int res = 0;

    // Sliding window XOR of sums
    for (int i = 0; i + k <= n; i++) {//doubt chilo?? why i+k<=n as prefix_sum size is n+1
        int sum = prefix_sum[i + k] ^ prefix_sum[i];//just change the previous solution with + to ^
        res ^= sum;
    }

    cout << res << endl;
    return 0;
}

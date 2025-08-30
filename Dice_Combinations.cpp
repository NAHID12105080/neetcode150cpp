#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int mod = 1e9 + 7;
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // base case

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 6 && i + j <= n; j++)
        {
            dp[i + j] = (dp[i + j] + dp[i]) % mod;
        }
    }

    cout << dp[n] << endl;
}

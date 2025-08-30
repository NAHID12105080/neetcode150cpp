#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int ans = 0;
        for (int k = 1; k <= n; k++)
        {
            if (n % k == 0)
            {
                int g = 0;
                for (int j = k; j < n; j++)
                {
                    g = gcd(g, v[j] - v[j - k]);
                }
                if (g != 1)
                    ans++;
            }
        }

        cout << ans << endl;
    }
}

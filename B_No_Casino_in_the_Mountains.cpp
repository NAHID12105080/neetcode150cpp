#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int cnt = 0;
        int i = 0;
        while (i <= n - k)
        {
            bool all_zero = true;
            for (int j = 0; j < k; j++)
            {
                if (a[i + j] != 0)
                {
                    all_zero = false;
                    break;
                }
            }
            if (all_zero)
            {
                cnt++;
                i += k + 1;
            }
            else
            {
                i++;
            }
        }

        cout << cnt << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

int t, n, k, z, i, m, x, s;

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n >> k >> z;
        vector<int> a(n);

        for (i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        i = 0;
        m = x = s = 0;

        for (i = 0; i <= k; ++i)
        {
            s += a[i];
            x = max(x, a[i] + a[i + 1]);
            m = max(m, s + x * min(z, (k - i) / 2));
        }

        cout << m << '\n';
    }

    return 0;
}

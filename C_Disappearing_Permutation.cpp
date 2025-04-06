#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, a[100010], k, x, b[100010];

signed main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        x = 0;
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
        {
            cin >> k;
            while (!b[k])
            {
                b[k] = 1;
                k = a[k];
                x++;
            }
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
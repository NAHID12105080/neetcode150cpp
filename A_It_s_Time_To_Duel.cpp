#include <bits/stdc++.h>
using namespace std;
int t, n, a[101];
signed main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        int flag = 0, f = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (i > 1 && a[i] == a[i - 1] && a[i] == 0)
                flag = 1;
            if (a[i] == 0)
                f = 1;
        }
        if (flag || f == 0)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
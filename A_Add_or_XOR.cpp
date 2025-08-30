#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define INF(t) numeric_limits<t>::max()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        if (b < a - 1 || (b < a && a % 2 == 0))
        {
            cout << "-1\n";
            continue;
        }
        if (b == a - 1)
        {
            cout << y << "\n";
            continue;
        }
        int ans = 0;
        while (a != b)
        {
            if (a % 2 == 0)
                ans += min(x, y);
            else
                ans += x;
            a++;
        }
        cout << ans << "\n";
    }

    return 0;
}
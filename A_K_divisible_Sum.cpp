#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LONG_MAX >> 1;

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

        int low = 0;
        high = n;

        while (low < high)
        {
            int mid = (low + high + 1) / 2;
            if (mid * (mid + 1) / 2 <= k)
            {
                low = mid; // mid is a valid answer
            }
            else
            {
                high = mid - 1; // mid is too large
            }
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
int n, m, k, l, t;
string s;
long long p, x;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s >> p;
        n = s.size();
        x = 0;
        while (p > n - x)
            p -= n - x++;
        m = 0;
        for (int i = 0; i < n; ++i)
        {
            while (m && x && s[m - 1] > s[i])
                --x, --m;
            s[m++] = s[i];
        }
        cout << s[p - 1];
    }
    return 0;
}
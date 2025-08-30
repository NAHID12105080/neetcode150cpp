#include <bits/stdc++.h>
using namespace std;

long long t, n, m, a, s, k;

int main()
{

    cin >> t;
    while (t--)
    {

        cin >> n;

        m = s = k = 0;
        for (int i = 0; i < n; i++)
        {

            cin >> a;

            s += a;
            k += a & 1;
            m = max(m, a);
        }
        if (k == 0 || k == n) // if all odd or even parity
            cout << m << endl;
        else
            cout << s + 1 - k << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n - 1; i >= 1; i--)
        a[i] = a[i] + a[i + 1];
    ll t = (x - 1) / a[1];
    int i = n;
    while (t * a[1] + a[i] < x)
        i--;
    cout << max(0ll, (k - t - 1) * n + i) << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
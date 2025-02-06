#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(a, n) ll a[n]; f(i, n) cin >> a[i]
#define nline '\n'

void solve() {
    ll n, k;
    cin >> n >> k;
    ia(a, n);
    
    if (n == k) {
        for (ll i = 1; i < n; i += 2) {
            if (a[i] != (i / 2) + 1) {
                cout << (i / 2) + 1 << nline;
                return;
            }
        }
        cout << n / 2 + 1 << nline;
    } else {
        if (count(a + 1, a + n - k + 2, 1) == n - k + 1)
            cout << 2 << nline;
        else
            cout << 1 << nline;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}

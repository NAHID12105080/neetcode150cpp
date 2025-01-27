#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(a, n) \
ll a[n];     \
f(i, n) cin >> a[i]
#define iv(v,n) vector<ll> v(n); f(i,n) cin >> v[i]
#define MOD (1000000007)
#define INF 1000000000000000000LL // Infinity for ll
#define mp make_pair
#define nline '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"

void solve() {
    ll n;
    cin >> n;
    ia(a,n);
    f(i,n) {
        if(a[i] <= max(2*(n-1-i), 2*i) ) {
            no;
            return;
        }
    }
    yes;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

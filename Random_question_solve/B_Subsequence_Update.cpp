#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(a, n) \
ll a[n];     \
f(i, n) cin >> a[i]
#define MOD (1000000007)
#define INF 1000000000000000000LL // Infinity for ll
#define mp make_pair
#define nline '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"

void solve() {
	ll n,l,r;
	cin >> n >> l >> r;
	l--, r--;
	ia(a,n);
	vector<ll> b,c;
	for(ll i = l; i < n; i++) {
		b.push_back(a[i]);
	}
	for(ll i = 0; i <= r; i++) {
		c.push_back(a[i]);
	}
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());

	ll sum1 = accumulate(b.begin(), b.begin() + (int)(r-l+1), 0LL);
	ll sum2 = accumulate(c.begin(), c.begin() + (int)(r-l+1), 0LL);

	cout << min(sum1, sum2) << nline;
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

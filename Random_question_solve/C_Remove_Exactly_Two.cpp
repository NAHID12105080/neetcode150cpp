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
	ll n;
	cin >> n;
	set<pair<ll,ll>> edges;
	vector<ll> deg(n+1);
	f(i,n-1) {
		ll a,b;
		cin >> a >> b;
		edges.insert(mp(a,b));
		edges.insert(mp(b,a));
		deg[a]++;
		deg[b]++;
	}
	ll ans = 0;
	vector<pair<ll,ll>> b;
	f(i,n) {
		b.push_back(mp(deg[i+1], i+1));
	}
	sort(b.begin(), b.end(), greater<pair<ll,ll>>());
	f(i,n) {
		for(ll j = i+1; j < n; j++) {
			if(edges.find(mp(b[i].second, b[j].second)) == edges.end()) {
				ans = max(ans, b[j].first + b[i].first - 1);
				break;
			}
		}
	}

	for(auto x : edges) {
		ans = max(ans, deg[x.first] + deg[x.second] - 2);
	}
	cout << ans << nline;
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

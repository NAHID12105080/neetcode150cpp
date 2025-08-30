#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = -1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        vector<ll> a(n);
        for (ll& x : a) cin >> x;
        
        vector<vector<ll>> dl(n+1), dr(n+1);
        dl[0] = {0};
        for (int i=1; i<=n; ++i) {
            int m = min(i, k);
            dl[i].assign(m+1, INF);
            for (int j=0; j<dl[i-1].size(); ++j) {
                dl[i][j] = max(dl[i][j], dl[i-1][j]);
                if (j+1 <= m) dl[i][j+1] = max(dl[i][j+1], dl[i-1][j] + a[i-1]);
            }
        }
        
        dr[n] = {0};
        for (int i=n-1; i>=0; --i) {
            int m = min(n-i, k);
            dr[i].assign(m+1, INF);
            for (int j=0; j<dr[i+1].size(); ++j) {
                dr[i][j] = max(dr[i][j], dr[i+1][j]);
                if (j+1 <= m) dr[i][j+1] = max(dr[i][j+1], dr[i+1][j] + a[i]);
            }
        }
        
        ll ans = INF;
        for (int p=0; p<n; ++p) {
            ll t = a[p];
            if (p == 0) { if (k < dr[1].size()) t += dr[1][k]; }
            else if (p == n-1) { if (k < dl[n-1].size()) t += dl[n-1][k]; }
            else for (int l=1; l<=min(k-1, p); ++l) {
                int r = k-l;
                if (r>0 && r<=n-p-1 && l<dl[p].size() && r<dr[p+1].size())
                    t = max(t, a[p] + dl[p][l] + dr[p+1][r]);
            }
            ans = max(ans, t);
        }
        cout << ans << '\n';
    }
}
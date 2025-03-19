#include<bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n * k);
    for (int &a : v) cin >> a;
    sort(v.rbegin(), v.rend());
    long long ans = 0;
    for (int i = n / 2, cnt = 0; cnt < k; i += n / 2 + 1) {
        ans += v[i];
        cnt++;
    }
    cout << ans << endl;
  }
  return 0;
}
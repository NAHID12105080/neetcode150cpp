#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LONG_MAX >> 1;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    (s=="yes")?cout<<"YES"<<endl:cout<<"NO"<<endl;
  }
}

// #include <algorithm>
// #include <vector>

// std::vector<int> source = {1, 2, 3, 4};
// std::vector<int> dest(source.size()); // Must pre-size the destination or use back_inserter

// std::transform(source.begin(), source.end(), dest.begin(),
//                [](int x) { return x * 2; }); // Example using a lambda

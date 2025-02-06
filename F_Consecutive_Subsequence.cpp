#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 20;
int n, a[N];
//size of the array is too large (1e9); we use map instead of array
map <int, int> dp;
int ans, curr;
vector <int> vec;

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[a[i]] = max(dp[a[i]], dp[a[i] - 1] + 1);
        
        if (dp[a[i]] > ans) {
            ans = dp[a[i]];
            curr = a[i];
        }
    }
    
    cout << ans << '\n';
    
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == curr) {
            curr--;
            vec.push_back(i);
        }
    }
    
    reverse(vec.begin(), vec.end());
    for (int i: vec) cout << i + 1 << ' ';
    cout << '\n';
}
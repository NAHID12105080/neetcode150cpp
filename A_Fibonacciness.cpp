#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9+7;
const int INF = LONG_MAX >> 1;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc;
    cin >> tc;
    while (tc--) 
    {    
    map<int, int> freq;
    int A1, A2, A4, A5;
    cin >> A1 >> A2 >> A4 >> A5;
    freq[A1 + A2]++;
    freq[A4 - A2]++;
    freq[A5 - A4]++;
    int most = 0;
 
    for (auto &[a, cnt] : freq)
        most = max(most, cnt);
 
    cout << most << endl;    
    }
}
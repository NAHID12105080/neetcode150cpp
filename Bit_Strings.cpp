#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

int binExp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

signed main() {
    int n;
    cin >> n;
    int s = binExp(2, n, MOD);
    cout << s << endl;
    return 0;
}

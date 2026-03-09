#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int>a(n);
        for (int &x : a) cin >> x;
        sort(a.rbegin(), a.rend());

        long long s = 0;
        for (int i = 0; i < n; i++)
            if (i % 2 == 0) s += a[i];
            else {
                int d = min(k, a[i-1] - a[i]);// taking min value of k possible and adding it to a[i] in next step
                a[i] += d; k -= d;//substracting k with the minValue of k taken
                s -= a[i];
            }

        cout << s << "\n";
    }
}
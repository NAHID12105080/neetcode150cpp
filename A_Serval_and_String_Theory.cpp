#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        bool flag = true;

        flag = count(s.begin(), s.end(), s[0]) == n;
        if (flag) { cout << "NO"<<endl; continue; }

      
        bool u = false;
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - 1 - i]) {
                u = s[i] < s[n - 1 - i];
                break;
            }
        }
        cout << (u or k >= 1 ? "YES" : "NO") << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, a;
        cin >> n >> m;
        vector<int> Z(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a;
            while (a % 10 == 0) {
                a /= 10;
                Z[i]++;
            }
            m -= to_string(a).length();
        }

        sort(Z.rbegin(), Z.rend()); // Sort descending
        
        for (int i = 1; i < n; i += 2) {
            m -= Z[i];
        }

        cout << (m >= 0 ? "Anna\n" : "Sasha\n");
    }
}

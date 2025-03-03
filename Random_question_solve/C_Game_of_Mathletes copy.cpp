#include<bits/stdc++.h>
using namespace std;

void run_case() {
    int N, K;
    cin >> N >> K;
    vector<int> freq(2 * N + 1, 0);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }
    i
    nt ans = 0;
    for (int x = 0, y = K; x <= y; x++, y--)
        if (x == y)
            ans += freq[x] / 2;
        else
            ans += min(freq[x], freq[y]);
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin >> tests;
    while (tests-- > 0)
        run_case();
}

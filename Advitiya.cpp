#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc;
    cin >> tc;
    while (tc--) {  
        string given = "ADVITIYA"; 
        string s;
        cin >> s;
        
   
        int sum = 0;
        for (int i = 0; i < 8; i++) {
            int change = (given[i] - s[i] + 26) % 26;  
            sum += change;
        }

        cout << sum << endl;
    }
}

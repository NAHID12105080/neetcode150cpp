#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    map<int, int> freq;

    // First window
    for (int i = 0; i < k; i++)
        freq[arr[i]]++;

    cout << freq.size() << " ";

    // Remaining windows
    for (int i = k; i < n; i++)
    {
        // Add new element
        freq[arr[i]]++;

        // Remove old element
        freq[arr[i - k]]--;
        if (freq[arr[i - k]] == 0)
            freq.erase(arr[i - k]);

        cout << freq.size() << " ";
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 10; // Maximum array size
int n, arrivalTimes[N], minCost[N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arrivalTimes[i];

        // Find the index of the first train within the last 90 minutes
        int index90 = upper_bound(arrivalTimes, arrivalTimes + i, arrivalTimes[i] - 90) - arrivalTimes;

        // Find the index of the first train within the last 1440 minutes (24 hours)
        int index1440 = upper_bound(arrivalTimes, arrivalTimes + i, arrivalTimes[i] - 1440) - arrivalTimes;

        // Default cost if the ticket is bought individually
        minCost[i] = (i ? minCost[i - 1] : 0) + 20;

        // Minimum cost if using a 90-minute pass
        minCost[i] = min(minCost[i], (index90 ? minCost[index90 - 1] : 0) + 50);

        // Minimum cost if using a 24-hour pass
        minCost[i] = min(minCost[i], (index1440 ? minCost[index1440 - 1] : 0) + 120);

        // Output the cost difference for the current train
        cout << (minCost[i] - (i ? minCost[i - 1] : 0)) << '\n';
    }

    return 0;
}

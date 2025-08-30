#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
long long int a[100005];
long long int b[100005];
int main()
{
	int n, x;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
	 	cin >> x;
		a[x] += x;		
	}

	for (int i = 2; i <= 100000; ++i)
		a[i] = max (a[i-1], a[i]+a[i-2]);	

	cout << a[100000];
	return 0;
}


//memoization dp:----------->
// #include <iostream>
// #include <cstring>
// using namespace std;

// long long a[100005];  // Stores sum of values
// long long dp[100005]; // Memoization array

// // Recursive function with memoization
// long long solve(int i) {
//     if (i <= 0) return 0; // Base case
//     if (dp[i] != -1) return dp[i]; // Return if already computed

//     // Either take 'i' (a[i] + solve(i-2)) or skip it (solve(i-1))
//     return dp[i] = max(solve(i - 1), a[i] + solve(i - 2));
// }

// int main() {
//     int n, x;
//     cin >> n;
    
//     memset(dp, -1, sizeof(dp)); // Initialize memoization array

//     for (int i = 0; i < n; ++i) {
//         cin >> x;
//         a[x] += x;  // Sum occurrences of each number
//     }

//     cout << solve(100000); // Start from the highest index
//     return 0;
// }

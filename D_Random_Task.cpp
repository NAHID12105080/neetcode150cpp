#include <bits/stdc++.h>
#define int long long
using namespace std ;

int const N = 65 , inf = 1e18 ;
int m , k , dp[N][N] ;

void pre () {
	for (int i = 0 ; i < N ; i ++) {
		dp[i][0] = dp[i][i] = 1 ;
		for (int j = 1 ; j < i ; j ++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] ; 
		}
	}
}

void in () {
	cin >> m >> k ;
}

inline int get (int v) {
	int cur = 0 , res = 0 ;
	
	for (int i = 60 ; i >= 0 ; i --) {
		if (v & (1ll << i)) {
			res += dp[i][k - cur] ;
			cur ++ ;
		}

		if (cur == k) {
			break ;
		}
	}

	return res ;
}

int32_t main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	pre() ;
	in() ;
	int L = 0 , R = inf ;
	while (L < R - 1) {
		int mid = (L + R) >> 1 ;

		if (get(2 * mid) - get(mid) < m) {
			L = mid ;
		}
		else {
			R = mid ;
		}
	}
	cout << R << '\n' ;
}
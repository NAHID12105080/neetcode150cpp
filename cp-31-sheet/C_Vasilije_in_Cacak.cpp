#include <iostream>

using namespace std;

int main(){
	int t; //read the number of test cases
	cin >> t;
	while(t--){
		long long n, k,x; //read n, x, k for each test case
		cin >> n >> k >> x;
		if(2*x>=k*(k+1) && 2*x<=n*(n+1)-(n-k)*(n-k+1)){ //check if k is between the minimum and maximum sum 
			cout << "YES\n";
		}
		else cout << "NO\n";
	}	
}
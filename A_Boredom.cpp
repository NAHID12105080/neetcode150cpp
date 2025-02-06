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
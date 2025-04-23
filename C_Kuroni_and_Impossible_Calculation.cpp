#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int num[n];
    long long int x = 1;
    for (int j = 0; j < n; j++)
    {
        cin >> num[j];
        for (int i = 0; i < j && x != 0; i++)
            x = x * abs(num[i] - num[j]) % m;
    }
    cout << x % m << endl;
}

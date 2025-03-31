#include <iostream>

using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        long long int n;
        cin >> n;
        long long int cur = 1;
        while (n != 0)
        {
            long long int x = n % 10;
            cur *= ((x + 1) * (x + 2)) / 2;
            n /= 10;
        }
        cout << cur << endl;
    }
    return 0;
}
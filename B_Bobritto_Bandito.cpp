#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, l, r;
        cin >> n >> m >> l >> r;
        int v = min(m, r);
        cout << -m + v << " ";
        cout << v << endl;
    }
}
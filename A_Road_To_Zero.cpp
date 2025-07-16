#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, a, b;
        cin >> x >> y;
        cin >> a >> b;

        b = min(b, 2 * a);

        if (x < y)
            swap(x, y);

        cout << y * b + (x - y) * a << endl;
    }
    return 0;
}

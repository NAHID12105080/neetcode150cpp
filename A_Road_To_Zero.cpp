#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x, y, a, b;
        cin >> x >> y;
        cin >> a >> b;

        // Use the cheaper between doing two a-operations or one b-operation
        long long cost_both = min(b, 2 * a);

        long long min_val = min(x, y);
        long long diff = abs(x - y);

        long long total_cost = min_val * cost_both + diff * a;
        cout << total_cost << '\n';
    }
    return 0;
}

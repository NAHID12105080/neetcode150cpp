#include <bits/stdc++.h>
using namespace std;
int t, x, y;

int main() {
  for (cin >> t; t--;) {
    cin >> x;
    y =  (~x & -~x);
    cout << (y < x ? y : -1) << '\n';
  }
  return 0;
}
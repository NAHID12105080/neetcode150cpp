#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> at(n), bt(n), id(n);
    for(int i=0;i<n;i++){ cin>>at[i]>>bt[i]; id[i]=i; }

    sort(id.begin(), id.end(), [&](int a,int b){
        return at[a] < at[b];
    });

    int time = at[id[0]];
    for(int i : id){
        time += bt[i];
        cout << "P" << i+1 << " WT=" << time - at[i] - bt[i]
             << " TAT=" << time - at[i] << "\n";
    }
}

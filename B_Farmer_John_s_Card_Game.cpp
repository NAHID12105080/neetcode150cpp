#include<bits/stdc++.h>
using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;
    vector<int> location(N * M, -1);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            int card;
            cin >> card;
            location[card] = i;//stores the cows no which holds the card
        }

    for (int x = 0; x + N < N * M; x++)
        if (location[x] != location[x + N]) {//ensures that every group N cards (one card per cow) is owned by the same group of cows in the same order(if valid). 
            cout << -1 << '\n';
            return;
        }
    //another way to print the same 
    // for (int i = 0; i < N; i++)
    //     cout << location[i] + 1 << (i < N - 1 ? ' ' : '\n');

   for(int i=0;i<N;i++){
    cout<<location[i]+1<<" ";//outputing cows order of cards playing
   }
   cout<<endl;

}

int main() {
    ios::sync_with_stdio(false);


    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}

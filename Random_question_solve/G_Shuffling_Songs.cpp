#include <bits/stdc++.h>
using namespace std;
 
#define ll     long long
#define ff     first
#define ss     second
#define pb     push_back
 
int N;
string G[16],W[16];
bool poss[16][16];
bool dp[1<<16][16];
 
int main()
{
    int test;
    cin>>test;
 
    while(test--){
        cin>>N;
        for(int i=0;i<N;i++)
            cin>>G[i]>>W[i];
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                poss[i][j]=G[i]==G[j] || W[i]==W[j];
        }
 
        for(int i=0;i<1<<N;i++)
        {
            for(int j=0;j<N;j++)
                dp[i][j]=false;
        }
 
        for(int i=0;i<N;i++)
            dp[1<<i][i]=true;
 
        int ans=0;
 
        for(int i=1;i<1<<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(dp[i][j])
                {
                    ans=max(ans,__builtin_popcount(i));
                    for(int k=0;k<N;k++) if(!(i>>k&1) && poss[j][k]) dp[i|1<<k][k]=true;
                }
            }
        }
 
        cout<<N-ans<<"\n";
    }
}
 
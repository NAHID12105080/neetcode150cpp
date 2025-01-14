#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9+7;
const int INF = LONG_MAX >> 1;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc;
    cin >> tc;
    while (tc--) 
    {  
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
      string s;
      cin>>s;

      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
      }
    vector<int> R(n,0),C(m,0);//R[i] stores the sum of ith row and C[i] stores the sum of ith column

    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<m;j++){
            sum+=v[i][j];
        }
        R[i]=sum;
    }

    for(int i=0;i<m;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=v[j][i];
        }
        C[i]=sum;

    }

    int x=0,y=0;
    int cnt=0;

    while(cnt<n+m-1){
        if(s[cnt]=='D'){
            v[x][y]=-R[x];//as leaving the row, so updating row value with -R[x]
            R[x]+=v[x][y];//updating row value
            C[y]+=v[x][y];//updating column value
            x++;
        }
        else{
            v[x][y]=-C[y];
            C[y]+=v[x][y];
            R[x]+=v[x][y];
            y++;
        }
        cnt++;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    }
}
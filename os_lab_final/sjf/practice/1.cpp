#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> at(n),bt(n);

    for(int i=0;i<n;i++){
        cin>>at[i]>>bt[i];
    }

    vector<bool>done(n,false);

    int time=*min_element(at.begin(),at.end());

    for(int j=0;j<n;j++){
        int idx=-1,mn=1e9;
        for(int i=0;i<n;i++){
            if(!done[i] && at[i]<=time && bt[i]<mn){
                idx=i,mn=bt[i];
            }
        }
        done[idx]=true;
        time+=bt[idx];
        cout<<"P"<<idx+1 << "   wt    " << time-bt[idx]-at[idx]<< " Tat "<< time-at[idx] <<endl;
        
    }
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int p,m; cin>>p>>m;
    vector<int> part(p), proc(m);
    for(int &x:part) cin>>x;
    for(int &x:proc) cin>>x;

    for(int i=0;i<m;i++){
        int idx=-1;
        for(int j=0;j<p;j++)
            if(part[j]>=proc[i] &&
               (idx==-1 || part[j]<part[idx]))
                idx=j;   // Best Fit
        if(idx!=-1){
            cout<<"P"<<i+1<<"->"<<idx+1<<"\n";
            part[idx]-=proc[i];
        }
    }
}

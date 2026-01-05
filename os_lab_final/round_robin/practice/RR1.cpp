#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;cin>>n>>q;
    vector<int>bt(n),rt(n),tat(n),wt(n);

    for(int i=0;i<n;i++){
        cin>>bt[i];
        rt[i]=bt[i];
    
    }

    int time=0,done=0;

    while(done<n){
        for(int i=0;i<n;i++){
           if(rt[i]>0){
             int exec=min(rt[i],q);
            rt[i]-=exec;
            time+=exec;

            if(rt[i]==0){
                tat[i]=time;
                wt[i]=time-bt[i];
                done++;
            }


           }


        }
    }

    for(int i=0;i<n;i++)
        cout<<"P"<<i+1<<" WT="<<wt[i]<<" TAT="<<tat[i]<<"\n";

}
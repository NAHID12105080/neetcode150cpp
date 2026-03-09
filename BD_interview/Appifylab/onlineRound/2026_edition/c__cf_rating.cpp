#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    vector<long long>a(n),b(n),c(n);

    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;
    for(auto &x:c) cin>>x;

    long long ans=0;

    for(int i=0;i<n;i++){
        long long t,s; 
        cin>>t>>s;

        if(s>0)
            ans+=max(c[i],a[i]-b[i]*t-50*(s-1));
    }

    cout<<ans<<endl;
}
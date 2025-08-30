#include<bits/stdc++.h>
using namespace std;
int n,i;
string s,r;
int main(){
cin>>n>>s;
for(;i<n;i++)if(r.size()%2==0||s[i]!=r.back())r+=s[i];
if(r.size()%2)r.pop_back();
cout<<n-r.size()<<endl<<r;
}

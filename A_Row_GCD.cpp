#include<bits/stdc++.h>
using namespace std;
int main()
{
long long x,g=0,n,m,a1;
cin>>n>>m>>a1;
for(int i=1;i<n;i++)
{
cin>>x;
g=gcd(g,abs(x-a1));
}
for(int i=0;i<m;i++)
{cin>>x;
cout<<gcd(g,a1+x)<<" ";
}
}
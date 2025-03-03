#include<bits/stdc++.h>
using namespace std;
int n,m,a[505][505],c[505];
void pr()
{
	cout<<"TAK"<<endl;
	for(int i=1;i<=n;i++)
	cout<<c[i]<<" ";
	exit(0);
}
int main()
{
	cin>>n>>m;
	int i,j,sum=0;
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++) 
	{
		cin>>a[i][j];
	}
	for(i=1;i<=n;i++) sum^=a[i][1],c[i]=1;
	if(sum!=0) pr();
	for(i=1;i<=n;i++)
	for(j=2;j<=m;j++)
	{
		if(a[i][j]!=a[i][1]) {c[i]=j;pr();} 
	}
	cout<<"NIE"<<endl;
}
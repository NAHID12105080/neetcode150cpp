#include <iostream>
using namespace std;
int T,x,y,n,m;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
	cin>>T;
	while(T--){
		cin>>x>>n>>m;y=x;
		m=min(m,31);n=min(n,31);
		x>>=n;
		for(int i=1;i<=m;i++)
        {
        x=(x+1)/2;
        y=(y+1)/2;
       }
		y>>=n;
		cout<<y<<' '<<x<<endl;
	}
}
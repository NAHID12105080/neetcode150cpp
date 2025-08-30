#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k,t;
	cin>>t;
	while (t--){
		cin>>n>>k;
		for (int i=1;i<=n-2;i++){
			cout<<((k%2)?n:(n-1))<<" ";
		}
		cout<<n<<" "<<n-1<<endl;
	} 
}
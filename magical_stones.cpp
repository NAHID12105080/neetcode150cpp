#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n],brr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            cin>>brr[i];
        }
        sort(arr,arr+n);
        sort(brr,brr+n);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=abs(arr[i]-brr[i]);
        }

        cout<<sum<<endl;
    }
}
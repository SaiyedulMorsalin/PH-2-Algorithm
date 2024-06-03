#include <bits/stdc++.h>
using namespace std;
int sum(int arr[],int n,int i){
    if(i == n) return 0;
    int s = arr[i] + sum(arr,n,i+1);
    return s;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<sum(arr,n,0);
    return 0;
}
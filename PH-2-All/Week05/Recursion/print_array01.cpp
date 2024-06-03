#include <bits/stdc++.h>
using namespace std;
void print(int arr[],int n,int i){
    if(i == n) return;
    cout<<arr[i]<<" ";
    print(arr,n,i+1);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    print(arr,n,0);
    return 0;
}
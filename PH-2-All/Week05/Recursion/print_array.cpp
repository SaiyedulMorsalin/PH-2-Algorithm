#include <bits/stdc++.h>
using namespace std;
void print_ar(int ar[],int i,int n){
    if(n == 0) return;
    print_ar(ar,i++,n-1);
    cout<<ar[i]<<" ";

}
int main(){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    print_ar(ar,0,n);
    return 0;
}
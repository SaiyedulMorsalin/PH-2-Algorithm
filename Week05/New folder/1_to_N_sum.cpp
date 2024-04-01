#include <bits/stdc++.h>
using namespace std;
int print(int n){
    if(n ==1) return 1;
    int sum = n+print(n-1);
    return sum;
    
}
int main(){
    int n;
    cin>>n;
    cout<<print(n);
    return 0;
}
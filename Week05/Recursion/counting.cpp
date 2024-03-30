#include <bits/stdc++.h>
using namespace std;
void count(int n){
    if(n==0) return;
    // cout<<n<<" ";// Tail Recursion
    count(n-1);
    cout<<n<<" ";//Head Recursion
}
int main(){
    int n;
    cin>>n;
    count(n);
    return 0;
}
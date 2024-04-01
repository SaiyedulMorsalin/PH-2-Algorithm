#include <bits/stdc++.h>
using namespace std;
void sayDigit(int n){
    if(n == 0){
        return;
        cout<<n<<" ";
    } 
    int digit = n%10;
    sayDigit(n/10);
    cout<<digit<<" ";
}
int main(){
    int n;
    cin>>n;
    sayDigit(n);
    
    
    return 0;
}
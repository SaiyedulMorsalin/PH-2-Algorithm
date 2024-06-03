#include <bits/stdc++.h>
using namespace std;
bool flag;
int rValue(int n,int i){
    if(n == i){
        flag = true;
        return 0;
    }
    int nibo = rValue(n,i*10);
    int nibona = rValue(n,i*20);
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        flag = false;
        int i = 1;
        int ans = rValue(n,i);
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;  
        }
    return 0;
}
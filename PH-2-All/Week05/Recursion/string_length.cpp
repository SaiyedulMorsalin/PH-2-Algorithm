#include <bits/stdc++.h>
using namespace std;
int print(string s,int i){
    if(s[i] == NULL) return 0;
    int l = print(s,i+1);
    return l+1;
}
int main(){
    string s;
    cin>>s;
    cout<<print(s,0);
    return 0;
}
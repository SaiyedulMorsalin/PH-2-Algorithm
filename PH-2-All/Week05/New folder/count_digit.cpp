#include <bits/stdc++.h>
using namespace std;
int cntDigit(int n){
    if(n == 0 ) return 1;
    int cnt = 0;
    if(n!= 0){
        cnt++;
        cntDigit(n/10);
    }
    return cnt;
}
int main(){
    int n;
    cin>>n;
    cout<<cntDigit<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int powerr(int n){
    if(n==0) return 1;
    int smallProblem = powerr(n-1);
    int bigProblem = 2*smallProblem;
    return bigProblem;
}
int main(){
    int n;
    cin>>n;
    cout<<powerr(n);
    return 0;
}
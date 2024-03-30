#include <bits/stdc++.h>
using namespace std;
int factorial(int n){
    if(n == 0 || n == 1) return 1;
    int smallProblem = factorial(n-1);
    int bigProblem = n*smallProblem;
    return bigProblem;
}
int main(){
    int n;
    cin>>n;
    cout<<factorial(n);
    return 0;
}
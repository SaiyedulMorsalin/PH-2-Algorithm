#include <bits/stdc++.h>
using namespace std;
int knapsack(int n,int wei[],int value[],int W){
    if( n == 0 || W == 0) return 0;
    if(wei[n-1]<=W){
        int nibo = knapsack(n-1,wei,value,W-wei[n-1])+value[n-1];
        int nibona = knapsack(n-1,wei,value,W);

        return max(nibo,nibona);
    }
    else{
        int nibona = knapsack(n-1,wei,value,W);
        return nibona;
    }
}
int main(){
    int n,w;
    cin>>n>>w;
    int we[n],value[n];
    for(int i=0;i<n;i++){
        cin>>we[i];
        cin>>value[i];
    }
    cout<<knapsack(n,we,value,w);
    return 0;
}
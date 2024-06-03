#include <bits/stdc++.h>
using namespace std;
int knapsack(int n,int weight[],int value[],int w){
    if(n ==0 || w == 0) return 0;

    if(weight[n]<=w){
        int nibo = knapsack(n-1,weight,value,w-weight[n])+value[n];
        int nibona = knapsack(n-1,weight,value,w);
        return max(nibo,nibona);
    }
    else{
        int nibona = knapsack(n-1,weight,value,w);
        return nibona;
    }

}
int main(){
    int n;
    cin>>n;
    int weight[n];
    int value[n];
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    int W;
    cin>>W;
    cout<<knapsack(n-1,weight,value,W);
    return 0;
}
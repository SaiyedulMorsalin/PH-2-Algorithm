#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int dp[N][N];
int adventure(int n,int we[],int value[],int w){
    if(n == 0 || w == 0) return 0;
    if(dp[n][w] != -1){
        return dp[n][w];
    }
    if(we[n-1]<=w){
        int nibo = adventure(n-1,we,value,w-we[n-1])+value[n];
        int nibona = adventure(n-1,we,value,w);
        return dp[n][w] = max(nibo,nibona);
    }
    else{
        int nibona = adventure(n-1,we,value,w);
        return dp[n][w]=  nibona;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,w;
        cin>>n>>w;
        int we[n];
        int value[n];
        for(int i=0;i<n;i++){
            cin>>we[i];
        }
        for(int i=0;i<n;i++){
            cin>>value[i];
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= w; j++)
            {
                dp[i][j] = -1;
            }
        }
        cout<<adventure(n,we,value,w)<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool subsetSumPossible(int ar[], int sum,int n) {
    
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= sum; s++) {
            if (ar[i - 1] <= s)
                dp[i][s] = dp[i - 1][s - ar[i - 1]] || dp[i - 1][s];
            else
                dp[i][s] = dp[i - 1][s];
        }
    }

    return dp[n][sum];
}

int main() {

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int ar[n];
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        int target = 1000 - m;
        
        if (subsetSumPossible(ar, target,n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        }
    
    return 0;
}
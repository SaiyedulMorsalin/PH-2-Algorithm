#include <bits/stdc++.h>
using namespace std;

vector<bool> dp;

bool canReachN(int N) {
    if (N == 1) return true; // Base case

    // Check if the value has already been calculated
    if (dp[N]) return dp[N];

    // Recursively call the function with N+3 and N*2
    bool canReach = canReachN(N + 3) || canReachN(N * 2);

    // Save the result in the dp array
    dp[N] = canReach;

    return canReach;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int N;
        cin >> N;

        dp.assign(N + 1, false);

        if (canReachN(N))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}

















// const int N = 1e5+5;
// int dp[N];
// bool canReachN(int n) {
//     if (n == 1) return true; 
//     if (dp[n] != -1) return dp[n];
//     bool canReach = canReachN(n + 3) || canReachN(n* 2);
//     dp[n] = canReach;
//     return canReach;
// }

// int main() {
//     int t;
//     cin>>t;
//     memset(dp,-1,sizeof(dp));
//     while(t--){
//         int n;
//         cin >> n;
//         if (canReachN(n))
//             cout << "YES" << endl;
//         else
//             cout << "NO" << endl;
//     }

//     return 0;
// }
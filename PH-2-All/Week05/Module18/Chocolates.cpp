#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(const vector<int>& nums, int sum) {
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i <= n; ++i)
        dp[i][0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            if (nums[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

bool canPartition(int arr[]) {
    int totalSum = 0;
    for (int num : arr)
        totalSum += num;

    // If totalSum is odd, it cannot be partitioned into two equal sum subsets
    if (totalSum % 2 != 0)
        return false;

    // Find if there's a subset with sum equal to half of total sum
    return subsetSum(nums, totalSum / 2);
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> nums = { 2,3, 4, 5};
    if (canPartition(arr))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}

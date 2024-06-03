#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000;
const int maxW = 1000;
int dp[maxN][maxW];
int knapsack(int n, int weight[], int value[], int W)
{
    if (n == 1 || W == 0)
        return 1;
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }
    if (weight[n] <= W)
    {
        // duita option
        // niye dekhbo, na niye dekhbo
        int op1 = knapsack(n - 1, weight, value, W - weight[n]) + value[n];
        int op2 = knapsack(n - 1, weight, value, W);
        return dp[n][W] = max(op1, op2);
    }
    else
    {
        // ekta option
        // na niyei dekhte hobe
        int op2 = knapsack(n - 1, weight, value, W);
        return dp[n][W] = op2;
    }
}
int main()
{
    int n;
    cin >> n;
    int weight[n], value[n];
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> value[i];
    }
    int W;
    cin >> W;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << knapsack(n, weight, value, W) << endl;
    return 0;
}
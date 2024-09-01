#include <bits/stdc++.h>
using namespace std;

int countWays(vector<int> coins, int n, int sum)
{
    // dp[i][j] stores the number of ways to make sum 'j' using first 'i' coins
    int dp[n + 1][sum + 1];

    // Initialization of base cases
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int j = 1; j <= sum; j++)
        dp[0][j] = 0;

    // Fill the table in bottom-up manner
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coins[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
        }
    }
    return dp[n][sum];
}

int minCoins(vector<int> coins, int n, int sum)
{
    // dp[i][j] stores the minimum number of coins required to make sum 'j' using first 'i' coins
    int dp[n + 1][sum + 1];

    // Initialization of base cases
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 1; j <= sum; j++)
        dp[0][j] = INT_MAX - 1;

    // Fill the table in bottom-up manner
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coins[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i]]);
        }
    }
    return dp[n][sum] == INT_MAX - 1 ? -1 : dp[n][sum];
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int n = coins.size();
    int sum = 12;
    cout << "Number of ways to make sum " << sum << " using given coins: ";
    cout << countWays(coins, n, sum) << endl;
    return 0;
}
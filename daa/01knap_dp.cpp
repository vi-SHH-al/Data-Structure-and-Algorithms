#include <iostream>
#include <climits>
using namespace std;

// tc: ^n
int knapSack(int v[], int w[], int n, int W)
{
    if (W < 0)
        return INT_MIN;
    if (n < 0 || W == 0)
        return 0;
    int in = v[n] + knapSack(v, w, n - 1, W - w[n]);
    int ex = knapSack(v, w, n - 1, W);
    return max(in, ex);
}

/*
TC: O(n*w)  
int knapSack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];

    // Initialize the dp matrix with zeros
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= W; j++)
            dp[i][j] = 0;

    // Fill the dp matrix with the maximum value that can be obtained for each weight capacity
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (wt[i-1] <= j) {
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}
*/
int main()
{
    int v[] = {10, 20, 30, 40, 60, 70};
    int w[] = {1, 2, 3, 6, 7, 4};
    int W = 7;
    int n = sizeof(v) / sizeof(v[0]);
    cout << "Knapsack value is " << knapSack(v, w, n - 1, W);
    return 0;
}
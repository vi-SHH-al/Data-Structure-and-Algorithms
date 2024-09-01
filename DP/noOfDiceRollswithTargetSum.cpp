/*
You have n dice, and each dice has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long int MOD = 1000000007;
    int solvebyMem(int n, int k , int target, vector<vector<int>> &dp){

        if(target == 0 && n ==0 ){
            return 1;
        }
        if(target != 0 && n == 0){
            return 0;
        }
        if(target ==0 && n!= 0){
            return 0;
        }
        if(dp[n][target] != -1){
            return dp[n][target];
        }

        int ans = 0;
        for(int i = 1; i <= k ;i++){
            int recAns = 0;
            if(target - i >= 0)
                recAns = solvebyMem(n-1, k, target-i, dp) % MOD;
            ans = (ans%MOD + recAns)%MOD;
        }
        dp[n][target] = ans;
        return ans;

    }

    int solvebyTab(int n, int k, int target){
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;

        for(int z = 1; z <= n; z++){
            for(int j = 0; j <= target ; j++){
                int ans = 0;
                for(int i = 1; i <= k ;i++){
                    int recAns = 0;
                    if(j - i >= 0)
                        recAns = dp[z-1][j-i] % MOD;
                    ans = (ans%MOD + recAns)%MOD;
                }
                dp[z][j] = ans;
            }
        }
        return dp[n][target];
    }

    int solvebyTabSO(int n, int k, int target){
        // vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        vector<int> curr(target+1,0);
        vector<int> prev(target+1,0);
        prev[0] = 1;

        for(int z = 1; z <= n; z++){
            for(int j = 0; j <= target ; j++){
                int ans = 0;
                for(int i = 1; i <= k ;i++){
                    int recAns = 0;
                    if(j - i >= 0)
                        recAns = prev[j-i] % MOD;
                    ans = (ans%MOD + recAns)%MOD;
                }
                curr[j] = ans;
            }
            prev = curr;
        }
        return prev[target];
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));

        // int ans = solvebyMem(n,k,target,dp);
        int ans = solvebyTab(n,k,target);
        return ans;
    }
};
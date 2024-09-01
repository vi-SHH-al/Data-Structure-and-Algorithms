#include<bits/stdc++.h>
using namespace std;

/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
*/

class Solution {
public:
    int solvebyRec(vector<int>& coins, int amount){
        // base case
        if(amount == 0){
            return 0;
        }
        int mini = INT_MAX;

        for(int i=0 ; i<coins.size(); i++){
            if(amount - coins[i] >= 0){
                int temp = solvebyRec(coins, amount - coins[i]);
                if(temp != INT_MAX){
                    int ans = 1 + temp;
                    mini = min(mini,ans);
                }
            }
            
        }
        return mini;
    }

    int solvebyDP(vector<int>& coins, int amount, vector<int>& dp){
         // base case
        if(amount == 0){
            return 0;
        }
        if(dp[amount] != -1){
            return dp[amount];
        }
        int mini = INT_MAX;

        for(int i=0 ; i<coins.size(); i++){
            if(amount - coins[i] >= 0){
                int temp = solvebyDP(coins, amount - coins[i], dp);
                if(temp != INT_MAX){
                    int ans = 1 + temp;
                    mini = min(mini,ans);
                }
            }
            
        }
        dp[amount] = mini;
        return dp[amount];
    }

    int solvebyTabulation(vector<int> &coins, int amount){
        int n = amount;
        vector<int> dp(n+1, -1);

        dp[0] = 0;

        for(int value = 1; value<=amount; value++){
            int mini = INT_MAX;
            for(int i=0 ; i<coins.size(); i++){
                if(value - coins[i] >= 0){
                    int temp = dp[value - coins[i]];
                    if(temp != INT_MAX){
                        int ans = 1 + temp;
                        mini = min(mini,ans);
                    }
                }
            }
        
            dp[value] = mini;
        }
    }
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount+1,-1);
        // int ans = solvebyRec(coins,amount);
        int ans = solvebyDP(coins,amount,dp);
        if(ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};
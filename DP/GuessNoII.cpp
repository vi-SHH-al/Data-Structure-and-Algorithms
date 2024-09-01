#include<bits/stdc++.h>
using namespace std;
/*
We are playing the Guessing Game. The game will work as follows:

I pick a number between 1 and n.
You guess a number.
If you guess the right number, you win the game.
If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.
*/


class Solution {
public:

    int solvebyrec(int s, int e){
        if(s > e){
            return 0;
        }
        if(s == e){
            return 0;
        }

        int ans = INT_MAX;

        for(int i = s; i <= e; i++ ){
            ans = min(ans, i + max(solvebyrec(s,i-1), solvebyrec(i+1,e)));
        }
        return ans;
    }

    int solvebyMem(int s, int e, vector<vector<int>>& dp){
        if(s > e){
            return 0;
        }
        if(s == e){
            return 0;
        }

        if(dp[s][e] != -1){
            return dp[s][e];
        }
        int ans = INT_MAX;

        for(int i = s; i <= e; i++ ){
            ans = min(ans, i + max(solvebyMem(s,i-1,dp), solvebyMem(i+1,e,dp)));
        
        }
        dp[s][e] = ans;
        return ans;
    }

    int solvebyTab(int n){
        vector<vector<int>> dp(n+2, vector<int>(n+1, 0));

        for(int s = n; s >= 1 ; s--){
            for(int e = 1; e <=n ; e++){
                if(s >= e){
                    continue;
                }
                int ans = INT_MAX;

                for(int i = s; i <= e; i++ ){
                    ans = min(ans, i + max(dp[s][i-1], dp[i+1][e] ));
        
                }
                dp[s][e] = ans;        
            }
        }
        return dp[1][n];
    }


    int getMoneyAmount(int n) {
        int s = 0;
        int e = n;
        
        // int ans = solvebyrec(s,e);

        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // int ans = solvebyMem(s,e,dp);

        int ans = solvebyTab(n);


        return ans;
    }
};

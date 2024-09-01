/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solveusingDP(string &w1, string &w2, int i, int j, vector<vector<int>> &dp){
        if(w1.length() == i){
            return w2.length() - j ;
        }
        if(w2.length() == j){
            return w1.length() - i ;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(w1[i] == w2[j]){
            ans = solveusingDP(w1,w2,i+1,j+1,dp);
        }else{
            int ins_op = 1 + solveusingDP(w1,w2, i, j+1,dp);
            int del_op = 1 + solveusingDP(w1,w2,i+1,j,dp);
            int rep_op = 1 + solveusingDP(w1,w2,i+1,j+1,dp);
            ans =  min(ins_op, min(del_op, rep_op));
        }
        dp[i][j] = ans;
        return ans;
    }

    int solveusingTab(string a, string b){
        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, -1));

        for(int col = 0 ; col <= b.length(); col++ ){
            dp[a.length()][col] = b.length() -  col;      ;
        }
        for(int row = 0; row <= a.length(); row++){
            dp[row][b.length()] = a.length() - row  ;
        }

        for(int i = a.length() -1; i>=0; i--){
            int ans = 0;
            for(int j = b.length()-1; j>=0; j--){
                if(a[i] == b[j]){
                    ans = dp[i+1][j+1];
                }else{
                    int ins_op = 1 + dp[i][j+1];
                    int del_op = 1 + dp[i+1][j];
                    int rep_op = 1 + dp[i+1][j+1];
                    ans =  min(ins_op, min(del_op, rep_op));
                }  
                dp[i][j] = ans;
            } 
        }

        return dp[0][0];
    }

    int solveusingTabSO(string a, string b){
        // vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, -1));

        // for(int col = 0 ; col <= b.length(); col++ ){
        //     dp[a.length()][col] = b.length() -  col;      ;
        // }
        // for(int row = 0; row <= a.length(); row++){
        //     dp[row][b.length()] = a.length() - row  ;
        // }

        vector<int> curr(a.size()+1, 0);
        vector<int> next(a.size()+1, 0);

        for(int row = 0; row< a.length(); row++){
            next[row] = a.length() - row;
        }

     for(int j = b.length()-1; j>=0; j--){
        curr[a.length()] = b.length() - j;
         int ans = 0;
        for(int i = a.length() -1; i>=0; i--){
           
            
                if(a[i] == b[j]){
                    ans = next[i+1];
                }else{
                    int ins_op = 1 + next[i];
                    int del_op = 1 + curr[i+1];
                    int rep_op = 1 + next[i+1];
                    ans =  min(ins_op, min(del_op, rep_op));
                }  
                curr[i] = ans;
            } 
            next = curr;
        }

        return next[0];
    }

    int minDistance(string word1, string word2) {
        // int i = 0;
        // int j = 0;

        // vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        // int ans = solve(word1, word2, i, j, dp);   

        return solveusingTabSO(word1,word2);
    }
};
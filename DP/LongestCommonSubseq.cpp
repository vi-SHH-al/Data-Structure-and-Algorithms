/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solveusingRec(string a, string b, int i, int j) {
        if (i >= a.length())
            return 0;
        if (j >= b.length())
            return 0;

        int ans = 0;
        if (a[i] == b[j]) {
            ans = 1 + solveusingRec(a, b, i + 1, j + 1);
        } else {
            int first = 0 + solveusingRec(a, b, i + 1, j);
            int second = 0 + solveusingRec(a, b, i, j + 1);
            ans = max(first, second);
        }
        return ans;
    }

    int solveusingMem(string& a, string& b, int i, int j,
                      vector<vector<int>>& dp) {
        if (i >= a.length())
            return 0;
        if (j >= b.length())
            return 0;
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if (a[i] == b[j]) {
            ans = 1 + solveusingMem(a, b, i + 1, j + 1, dp);
        } else {
            int first = 0 + solveusingMem(a, b, i + 1, j, dp);
            int second = 0 + solveusingMem(a, b, i, j + 1, dp);
            ans = max(first, second);
        }
        dp[i][j] = ans;
        return ans;
    }

    int solusingTab(string a, string b) {
        vector<vector<int>> dp(a.size() + 1,
                               vector<int>(b.size() + 1, 0));

        // for (int j = 0; j <= b.length(); j++) {
        //     dp[a.length()][j] = 0;
        // }

        // for (int i = 0; i <= a.length(); i++) {
        //     dp[i][b.length()] = 0;
        // }

        for (int i = a.length() - 1; i >= 0; i--) {
            int ans = 0;
            for (int j = b.length() - 1; j >= 0; j--) {

                if (a[i] == b[j]) {
                    ans = 1 + dp[i+1][j+1];
                } else {
                    int first = 0 + dp[i+1][j];
                    int second = 0 + dp[i][j+1];
                    ans = max(first, second);
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }
    
    int solusingTabSO(string a, string b) {
        // vector<vector<int>> dp(a.size() + 1,
        //                        vector<int>(b.size() + 1, 0));

        // for (int j = 0; j <= b.length(); j++) {
        //     dp[a.length()][j] = 0;
        // }

        // for (int i = 0; i <= a.length(); i++) {
        //     dp[i][b.length()] = 0;
        // }

        vector<int> curr (a.size()+1,0);
        vector<int> next (a.size()+1,0);
        for (int j = b.length() - 1; j >= 0; j--) {
        for (int i = a.length() - 1; i >= 0; i--) {
            int ans = 0;
            

                if (a[i] == b[j]) {
                    ans = 1 + next[i+1];
                } else {
                    int first = 0 + curr[i+1];
                    int second = 0 + next[i];
                    ans = max(first, second);
                }
                curr[i] = ans;
            }
            // shifting
            next = curr;    
        }

        return next[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        // int ans = solveusingRec(text1,text2,i,j);
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        int ans = solusingTabSO(text1, text2);
        return ans;
    }
};
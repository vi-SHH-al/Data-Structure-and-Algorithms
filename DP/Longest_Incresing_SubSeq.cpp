
/*
300. Longest Increasing Subsequence
Solved
Medium
Topics
Companies
Given an integer array nums, return the length of the longest strictly increasing 
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solveusingMem(vector<int> &nums, int curr, int prev, vector<vector<int>>& dp){
        if(curr >= nums.size()){
            return 0;
        }
        
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        int include = 0;
      
        if( prev == -1  || nums[curr] > nums[prev] ){
            include = 1+solveusingMem(nums, curr+1, curr,dp);
        }
        
        int exclude = 0 + solveusingMem(nums, curr+1, prev,dp);
        
        dp[curr][prev+1] = max(include,exclude);
        return dp[curr][prev+1];
        
    }
    
    int solveusingTab(vector<int> &nums){
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size()+1, 0));

        for(int curr=nums.size()-1; curr >=0; curr--){
            int ans = 0;
            for(int prev = curr-1; prev>=-1; prev-- ){
                
                int include = 0;
      
                if( prev == -1  || nums[curr] > nums[prev] ){
                    include = 1+dp[curr+1][curr+1];
                }
                
                int exclude = 0 + dp[curr+1][prev+1];
                
                dp[curr][prev+1] = max(include,exclude);
            }
        }

        return dp[0][0];
    }

    int solveusingTabSO(vector<int> &nums){
        // 

        vector<int> curr_row(nums.size()+ 1,0);
        vector<int> next_row(nums.size()+1,0);
        for(int curr=nums.size()-1; curr >=0; curr--){
            int ans = 0;
            for(int prev = curr-1; prev>=-1; prev-- ){
                
                int include = 0;
      
                if( prev == -1  || nums[curr] > nums[prev] ){
                    include = 1+next_row[curr+1];
                }
                
                int exclude = 0 + next_row[prev+1];
                
                curr_row[prev+1] = max(include,exclude);
            }
            next_row = curr_row;
        }

        return next_row[0];
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size()+1, -1));
        // int ans  = solveusingMem(nums, 0, -1, dp);
        // int ans = solveusingTab(nums);
        int ans = solveusingTabSO(nums);
        return ans;
    }
};
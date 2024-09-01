#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solvebyRec(vector<int>& nums, int index, int currsum, int target) {
        if (index == nums.size() || currsum > target) {
            return false;
        }
        if (currsum == target) {
            return true;
        }

        bool include =
            solvebyRec(nums, index + 1, currsum + nums[index], target);
        bool exclude = solvebyRec(nums, index + 1, currsum, target);

        bool ans = include or exclude;
        return ans;
    }

    bool solvebyMem(vector<int>& nums, int index, int currsum, int target,
                    vector<vector<int>>& dp) {
        if (index == nums.size() || currsum > target) {
            return false;
        }
        if (currsum == target) {
            dp[index][currsum] = 1;
            return true;
        }
        if (dp[index][currsum] != -1) {
            return dp[index][currsum];
        }

        bool include =
            solvebyMem(nums, index + 1, currsum + nums[index], target, dp);
        bool exclude = solvebyMem(nums, index + 1, currsum, target, dp);

        bool ans = include or exclude;
        dp[index][currsum] = ans;
        return ans;
    }

    bool solvebyTab(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, 0));
        int n = nums.size() - 1;

        for(int row = 0; row <= nums.size(); row++){
            dp[row][target] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = target; j >= 0; j--) {
                bool include = 0;

                if(j + nums[i] <= target)
                    include = dp[i + 1][j + nums[i]];
                bool exclude =dp[i + 1][j];

                bool ans = include or exclude;
                dp[i][j] = ans;
            }
        }
        return dp[0][0];   
    }

    bool solvebyTabSO(vector<int>& nums, int target) {
        // vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, 0));
        int n = nums.size() - 1;

        vector<int> curr(target+1,0);
        vector<int> next(target+1,0);
        

        // for(int row = 0; row <= nums.size(); row++){
        //     dp[row][target] = 1;
        // }
        curr[target] = 1;
        next[target] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = target; j >= 0; j--) {
                bool include = 0;

                if(j + nums[i] <= target)
                    include = next[j + nums[i]];
                bool exclude = next[j];

                bool ans = include or exclude;
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];   
    }


    bool canPartition(vector<int>& nums) {
        int index = 0;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum & 1)
            return false;

        int target = sum / 2;
        int currsum = 0;

        // bool ans = solvebyRec(nums,index,currsum, target);

        // vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
        // bool ans = solvebyMem(nums, index, currsum, target, dp);

        // bool ans = solvebyTab(nums,target);

        bool ans = solvebyTabSO(nums,target);
        return ans;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> &arr, map<pair<int,int>, int> &maxi, int start, int end,vector< vector<int>>& dp){

        if(start >= end){
            return 0;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        int ans = INT_MAX;

        for(int i=start; i < end; i++){
            ans = min(ans, maxi[{start,i}]*maxi[{i+1,end}]  + solve(arr,maxi,start,i,dp) + solve(arr,maxi,i+1,end,dp));
        }
        dp[start][end] = ans;
        return ans;
    }


    int solveusingTab(vector<int> &arr,map<pair<int,int>, int> &maxi){
        int n = arr.size() - 1;
        vector< vector<int>> dp(n+2, vector<int>(n+1, 0) );

        for(int start = n ; start >=0; start--){
            for(int end = 0; end <= n-1 ; end++){
                // if(start>end){
                //     continue;
                // }
                int ans = INT_MAX;
                for(int i=start; i < end; i++){
                    ans = min(ans, maxi[{start,i}]*maxi[{i+1,end}]  + dp[start][i] + dp[i+1][end]);
                }
                dp[start][end] = ans;
            }
        }

        return dp[0][n-1];

    }
    int mctFromLeafValues(vector<int>& arr) {
       map<pair<int,int> , int> maxi;
        
        for(int i=0; i<arr.size(); i++){
            maxi[{i,i}] = arr[i];
            for(int j = i+1; j<arr.size(); j++){
                maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
            }
        }
        vector< vector<int>> dp(arr.size()+1, vector<int>(arr.size()+1, -1) );
        return solve(arr,maxi,0, arr.size() - 1,dp);
    }; 
};
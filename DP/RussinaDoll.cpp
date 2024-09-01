/*
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

 

Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isfit(vector<int> a , vector<int> b){
        if(b[0] < a[0] && b[1] < a[1] )
            return true;
        else
            return false;
    }

    int solveusingTabSO(vector<vector<int>> &env){
        // 
        int n = env.size();
        vector<int> curr_row(n+ 1,0);
        vector<int> next_row(n+1,0);

        for(int curr=n-1; curr >=0; curr--){
            int ans = 0;
            for(int prev = curr-1; prev>=-1; prev-- ){
                
                int include = 0;
      
                if( prev == -1  || isfit(env[curr],env[prev] ) ){
                    include = 1 + next_row[curr+1];
                }
                
                int exclude = 0 + next_row[prev+1];
                
                curr_row[prev+1] = max(include,exclude);
            }
            next_row = curr_row;
        }

        return next_row[0];
    }
    bool isgreater(vector<int> a, vector<int>b){
        if(a[0] > b[0] && a[1] > b[1])
            return true;
        else
            return false;
    }

     int solveusingBS(vector<vector<int>> &env){
        int n = env.size();
        vector<int> ans;
        
        ans.push_back(env[0][1]);
        
        for(int i=1; i<n; i++){
            if(env[i][1] > ans.back() ) {
                ans.push_back(env[i][1]);
            }
            else{
                int index = lower_bound(ans.begin(), ans.end(), env[i][1]) - ans.begin();
                ans[index] = env[i][1];
            }
        }
        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),[](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];  // Sort in decreasing order of the second number.
        }
        return a[0] < b[0];  // Sort in increasing order of the first number.
    });

        return solveusingBS(envelopes);
    }
};
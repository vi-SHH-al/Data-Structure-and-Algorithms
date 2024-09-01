#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int tsp(int n, vector<vector<int>> &dist)
{
    // dp[i][mask] stores the shortest path starting from city 0, visiting all the cities in the set mask exactly once,
    // and ending at city i
    vector<vector<int>> dp(n, vector<int>(1 << n, INF));

    // Base case: starting from city 0 and visiting only city 0, the shortest path has length 0
    dp[0][1] = 0;

    // Fill the table in bottom-up manner
    for (int mask = 1; mask < (1 << n); mask += 2)
    { // iterate over all subsets of cities
        for (int i = 0; i < n; i++)
        {                           // iterate over all possible ending cities
            if (!(mask & (1 << i))) // if city i is not in the set of visited cities
                continue;
            for (int j = 0; j < n; j++)
            {                                     // iterate over all possible penultimate cities
                if (j == i || !(mask & (1 << j))) // if city j is not in the set of visited cities, or if j == i
                    continue;
                dp[i][mask] = min(dp[i][mask], dp[j][mask - (1 << i)] + dist[j][i]);
            }
        }
    }

    // Find the shortest path that starts and ends at city 0, visiting all cities exactly once
    int ans = INF;
    for (int i = 1; i < n; i++)
        ans = min(ans, dp[i][(1 << n) - 1] + dist[i][0]);
    return ans;
}

int main()
{
    int n = 4;
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};
    int shortest_path = tsp(n, dist);
    cout << "The shortest possible tour length is " << shortest_path << endl;
    return 0;
}

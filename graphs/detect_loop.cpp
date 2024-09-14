//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detect(vector<int> adj[], vector<int> &visited, int src){
        visited[src] = 1;
        
        // current no    de, parent node
        queue<pair<int,int>> q;
        
        q.push({src, -1});
        
        while(! q.empty()){
            
            int curr = q.front().first;
            int par = q.front().second;
            q.pop();
            visited[curr] = 1;
            for(auto it: adj[curr]){
                if(visited[it] == 1 && it != par)
                    return true;
                else
                    if(!visited[it])
                    q.push({it, curr});
            }
        }
        
        return false;
    }

    bool isDFS(int node, int parent, vector<int> &visited, vector<int> adj[]){
        visited[node] = 1;
        
        for(auto it:adj[node]){
          if( !visited[it]){
              if(isDFS(it,node, visited, adj) == true)
                return true;
          }
          else if( it != parent){
              return true;
          }
        }
        return false;
    }
     
    bool isCycle(int V, vector<int> adj[]) {
        // Code herev
        vector<int> visited(V,0);

        bool ans = false;
        for(int i = 0; i<V; i++){
            if( ! visited[i]){
                ans = detect(adj, visited, i);
                if(ans)
                return true;
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends   
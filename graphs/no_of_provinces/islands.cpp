#include<bits/stdc++.h>
using namespace std;


/* 547, Number of Provinces*/
class number_of_provinces {
  public:
    void dfs(vector<int> adj_list[],int i, vector<int> &visited){
        if(visited[i] == 1){
            return;
        }
        visited[i] = 1;
        
        for(int j = 0; j<adj_list[i].size(); j++){
            dfs(adj_list,adj_list[i][j], visited);
        }
        
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        vector<int> adj_list[adj.size()];
        int res=0;
        
        for(int i=0; i< adj.size(); i++){
            for(int j=0; j<adj.size(); j++){
                if(adj[i][j])
                adj_list[i].push_back(j);
            }
        }
        
        vector<int> visited(adj.size());
        for(int i=0; i<V;i++ ){
            if(visited[i] == 0){
                res++;
                dfs(adj_list,i, visited);
            }
        }
        
        return res;
    }
};
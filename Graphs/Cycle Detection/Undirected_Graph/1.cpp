// Cycle Detection in Undirected Graph -- 

// Problem Link -- https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// Code -- 


class Solution {
  public:
    bool solve(int node, int par, vector<int>& vis, vector<vector<int>>& adj){
        
        vis[node]=1;
        for(auto &it:adj[node]){
            if(!vis[it]){
                if(solve(it,node,vis,adj)) return true;
            }
            else if(it!=par) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(V,0);
        bool ans=false;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                ans= (ans | solve(i,-1,vis,adj));
            }
        }
        return ans;
    }
};
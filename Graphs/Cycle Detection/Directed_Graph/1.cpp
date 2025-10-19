// Cycle Detection in Directed Graph -- 

// Problem Link -- https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// Code -- 


class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int src,vector<int> adj[],vector<int>&visited,vector<int>&path){
        visited[src]=1;
        path[src]=1;
        for(auto it:adj[src]){
            if(!visited[it] && dfs(it,adj,visited,path)) return true;
            else if(path[it]) return true;
        }
        path[src]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>visited(V,0);
        vector<int>path(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i] && dfs(i,adj,visited,path)) return true;
        }
        return false;
    }
};
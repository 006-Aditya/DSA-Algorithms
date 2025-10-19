// Cycle Detection in Directed Graph -- 

// Problem Link -- https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// Code -- 


class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int n=V;
        vector<int>indegree(n,0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++) {
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            n--;
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(n>0) return true;
    return false;
    }
};
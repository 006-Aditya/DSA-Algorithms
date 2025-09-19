// problem link --

// https://leetcode.com/problems/parallel-courses-iii/description/?envType=problem-list-v2&envId=topological-sort

// Topological Sort

// code -- 


class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>adj(n+1);
        vector<int>indegree(n+1,0);
        for(int i=0;i<relations.size();i++){
            adj[relations[i][0]].push_back(relations[i][1]);
            indegree[relations[i][1]]++;
        }
        queue<int>q;
        vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                q.push(i);
                dp[i]=time[i-1];
            }
        }
        int res=0;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                int node=q.front();
                res=max(res,dp[node]);
                q.pop();
                for(auto it:adj[node]){
                    indegree[it]--;
                    dp[it]=max(dp[it],dp[node]+time[it-1]);
                    if(indegree[it]==0){
                        q.push(it);
                    }
                }
            }
        }
        return res;
    }
};
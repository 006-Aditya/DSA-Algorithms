// problem link --

// https://leetcode.com/problems/critical-connections-in-a-network/

// Tarjan's algorithm.

// code -- 


class Solution {
public:
    vector<vector<int> >adj;
    vector<vector<int> >res;
    vector<bool> visited;
    vector<int> tin, tlow;
    int timer;

    void dfs(int node, int par){
        visited[node]=true;
        tin[node]=timer;
        tlow[node]=timer;
        timer++;
        bool parent_skip=false; // not necessary
        for(auto &it:adj[node]){
            if(it==par && !parent_skip){
                parent_skip=true;
                continue;
            }
            if(!visited[it]){
                dfs(it,node);
                tlow[node]=min(tlow[node],tlow[it]);
                if(tlow[it]>tin[node]){
                    res.push_back({node,it});
                }
            }else{
                tlow[node]=min(tlow[node],tlow[it]);
            }
        }

    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        visited.assign(n,false);
        tin.assign(n,-1);
        tlow.assign(n,-1);
        adj.resize(n);
        timer=0;

        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,-1);
            }
        }

        return res;
    }
};





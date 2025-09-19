// problem link --

// https://cses.fi/problemset/task/1133

// Rerooting Dp

// code -- 


#include <bits/stdc++.h>
using namespace std;
#define int long long
const unsigned int M=1000000007;
#define p pair<int,int>
 
void dfs1(int node, int par, vector<vector<int>>& adj, vector<int>&subtree, vector<int>&dp) {
    subtree[node]=1;
    for (auto it : adj[node]) {
        if (it == par) continue;
        dfs1(it,node,adj,subtree,dp);
        subtree[node]+=subtree[it];
        dp[node]+=dp[it]+subtree[it];
    }
}
void dfs2(int n, int node, int par, vector<vector<int>>& adj, vector<int>&subtree, vector<int>&dp) {
    for (auto it : adj[node]) {
        if (it == par) continue;
        dp[it]=dp[node]-subtree[it]+(n-subtree[it]);
        dfs2(n,it,node,adj,subtree,dp);
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // subtree size
    vector<int>subtree(n+1,0);
    vector<int>dp(n+1,0);
    dfs1(1,-1,adj,subtree,dp);
    dfs2(n,1,-1,adj,subtree,dp);
    for(int i=1;i<=n;i++){
        cout << dp[i] << " ";
    }
    cout<<endl;
    return 0;
}
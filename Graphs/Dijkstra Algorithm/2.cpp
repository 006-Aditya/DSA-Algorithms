// problem link --

// https://cses.fi/problemset/task/1671

// Dijkstra Use

// code -- 

#include <bits/stdc++.h>
using namespace std;
#define int long long int
const unsigned int M=1000000007;
#define p pair<int,int>
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    int n,m; cin>>n>>m;
    vector<vector<p> >adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,l; cin>>u>>v>>l;
        adj[u].push_back({v,l});
    }
    priority_queue<p, vector<p>, greater<p> >pq;
    pq.push({0,1});
    vector<int>dis(n+1,LLONG_MAX);
    vector<int>vis(n+1,0);
    dis[1]=0;
    while(!pq.empty()){
        auto ptr=pq.top();
        int node=ptr.second;
        pq.pop();
        if(vis[node]) continue;
        vis[node]=true;
        for(auto it:adj[node]){
            int next=it.first;
            int cost=it.second;
            if(dis[node]+cost<dis[next]){
                dis[next]=dis[node]+cost;
                pq.push({dis[next],next});
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
    cout<<endl;
    return 0;
}
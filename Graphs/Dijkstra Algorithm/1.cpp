// problem link --

// https://cses.fi/problemset/task/1202/

// Dijkstra algorithm.

// code -- 

#include <bits/stdc++.h>
using namespace std;
#define int long long
const unsigned int M=1000000007;
#define p pair<int,int>


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
        
        int n,m; cin>>n>>m;
        vector<vector<p> >adj(n+1);
        for(int i=0;i<m;i++){
            int a,b,c; cin>>a>>b>>c;
            adj[a].push_back({b,c});
        }
        // apply dijkstra 
        vector<int>dist(n+1,LLONG_MAX);
        dist[1]=0;
        priority_queue<p, vector<p>, greater<p> >pq;
        pq.push({0,1});
        while(!pq.empty()){
            auto [price, city] =pq.top();
            pq.pop();
            for(auto it:adj[city]){
                int nextCity=it.first;
                int newCost=it.second;
                if(price+newCost<dist[nextCity]){
                    dist[nextCity]=price+newCost;
                    pq.push({dist[nextCity],nextCity});
                }
            }
        }
       
        // Step 2: DP over shortest path DAG
        vector<int> ways(n+1,0), minF(n+1,LLONG_MAX), maxF(n+1,0);
        ways[1] = 1;
        minF[1] = 0;
        maxF[1] = 0;
    
        vector<int> order(n);
        iota(order.begin(), order.end(), 1);
        sort(order.begin(), order.end(), [&](int a,int b){
            return dist[a] < dist[b];
        });
    
        for(int u: order){
            for(auto [v,w]: adj[u]){
                if(dist[v] == dist[u] + w){
                    ways[v] = (ways[v] + ways[u]) % M;
                    minF[v] = min(minF[v], minF[u] + 1);
                    maxF[v] = max(maxF[v], maxF[u] + 1);
                }
            }
        }
    
        cout << dist[n] << " " << ways[n] << " " << minF[n] << " " << maxF[n] << "\n";
            
    return 0;
}
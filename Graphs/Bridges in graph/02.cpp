// problem link --

// https://codeforces.com/contest/1986/problem/F

// Tarjan's algorithm.

// code -- 

#include <bits/stdc++.h>
using namespace std;
#define int long long
const unsigned int M=1000000007;
#define p pair<int,int>

int n,m;
int res;
vector<vector<int> >adj;
vector<bool> visited;
vector<int> subtree;
vector<int> tin, tlow;
int timer;

void dfs(int node, int par){
    visited[node]=true;
    tin[node]=timer;
    tlow[node]=timer;
    timer++;
    bool parent_skip=false;
    subtree[node]=1;
    for(auto &it:adj[node]){
        if(it==par && !parent_skip){
            parent_skip=true;
            continue;
        }
        if(!visited[it]){
            dfs(it,node);
            tlow[node]=min(tlow[node],tlow[it]);
            subtree[node]+=subtree[it];
            if(tlow[it]>tin[node]){
                int size1=subtree[it];
                int size2=n-size1;
                int temp=((size1*(size1-1))/2) + ((size2*(size2-1))/2);
                res=min(res,temp);
            }
        }else{
            tlow[node]=min(tlow[node],tlow[it]);
        }
    }

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin>>t;
    while(t--){
        cin>>n>>m;
        
        res=(n*(n-1))/2;
        visited.assign(n,false);
        tin.assign(n,-1);
        tlow.assign(n,-1);
        subtree.assign(n,0);
        adj.assign(n, {});
        timer=0;
        
        for(int i=0;i<m;i++){
            int a,b; cin>>a>>b;
            a--; b--; 
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,-1);
            }
        }
        
        cout<<res<<endl;
    }
}
        
    




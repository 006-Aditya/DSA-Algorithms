// DSU Template -- 

// Problem Link -- https://cses.fi/problemset/task/1676/

// Code -- 

#include <bits/stdc++.h>
using namespace std;
#define int long long
const unsigned int M=1000000007;
#define p pair<int,int>

class DSU{
public:
    vector<int>par,size;
    int components;
    int maxSize;
    DSU(int n){
        par.resize(n);
        iota(par.begin(),par.end(),0);
        size.assign(n,1);
        components=n;
        maxSize=1;
    }  
    int find(int x){
        if(x==par[x]) return x;
        return par[x]=find(par[x]);
    }
    void unionBySize(int a, int b){
        int par_a=find(a);
        int par_b=find(b);
        if(par_a==par_b) return;
        if(size[par_a]>=size[par_b]){
            par[par_b]=par_a;
            size[par_a]+=size[par_b];
        }
        else{
            par[par_a]=par_b;
            size[par_b]+=size[par_a];
        }
        maxSize=max(maxSize,size[par_a]);
        maxSize=max(maxSize,size[par_b]);
        components--;
    }
};


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
        
        int n,m; cin>>n>>m;
        DSU dsu(n+1);
        for(int i=0;i<m;i++){
            int a,b; cin>>a>>b;
            dsu.unionBySize(a,b);
            cout<<dsu.components-1<<" "<<dsu.maxSize<<endl;
        }
        
    return 0;
}


// problem link -- 

// https://maang.in/contests/attempts/52739?problem_id=42


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
        
    int n,k; cin>>n>>k;
    vector<vector<int> >camp(n);
    for(int i=0;i<n;i++){
        int vi,ei; cin>>vi>>ei;
        camp[i]={vi,ei};
    }
    vector<vector<int> >naval(n);
    for(int i=0;i<n;i++){
        vector<vector<int> >edges;
        for(int j=0;j<camp[i][1];j++){
            int a,b,l; cin>>a>>b>>l;
            edges.push_back({l,a,b});
        }
        // apply krushkals on graph
        sort(edges.begin(),edges.end());
        DSU dsu(camp[i][0]);
        int cost=0,count=0;
        for(int j=0;j<edges.size();j++){
            int a=edges[j][1]-1;
            int b=edges[j][2]-1;
            int l=edges[j][0];
            if(dsu.find(a)!=dsu.find(b)){
                dsu.unionBySize(a,b);
                cost+=l;
                count++;
                if(count==camp[i][0]-1) break;
            }   
        }
        naval[i]={cost,i+1};
    }
    sort(naval.rbegin(),naval.rend());
    cout<<naval[k-1][1]<<" "<<naval[k-1][0]<<endl;
    return 0;
}
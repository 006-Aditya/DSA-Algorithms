// Binary Lifting/ Jump -- 

// Problem Link -- https://cses.fi/problemset/task/1650/

// Code -- 


#include <bits/stdc++.h>
using namespace std;
#define int long long
const unsigned int M=1000000007;
#define p pair<int,int>
 
const int MAXN=200001;
int table[MAXN][20];
int logVal[MAXN];
 
int solve(int a, int b){
    if(a>b) return 0;
    if(a==b){
        return table[a][0];
    }
    int len=b-a+1;
    int k=logVal[len];
    int ans=0;
    ans=(ans^table[a][k])^solve(a+(1<<k),b);
    return ans;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    int n,q; cin>>n>>q;
    vector<int>x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    
    // fill log values
    logVal[1]=0;
    for(int i=2;i<=200000;i++){
        logVal[i]=logVal[i/2]+1;
    }
    
    // fill sparse table
    for(int i=0;i<n;i++) table[i][0]=x[i];
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;i+(1<<j)<=n;i++){
            table[i][j]=( table[i][j-1] ^ table[i+(1<<(j-1))][j-1] );
        }
    }
    
    while(q--){
        int a,b; cin>>a>>b;
        a--; b--;
        cout<<solve(a,b)<<endl;
    }
    
    return 0;
}

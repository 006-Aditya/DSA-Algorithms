// Binary Lifting/ Jump -- 

// Problem Link -- https://cses.fi/problemset/task/1647

// Code -- 

#include <bits/stdc++.h>
using namespace std;
#define int long long
const unsigned int M=1000000007;
#define p pair<int,int>
 
const int MAXN=200001;
int table[MAXN][20];
int logVal[MAXN];
 
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
            table[i][j]=min(table[i][j-1],table[i+(1<<(j-1))][j-1]);
        }
    }
    
    while(q--){
        int a,b; cin>>a>>b;
        a--; b--;
        int len=b-a+1;
        int k=logVal[len];
        cout<<min(table[a][k],table[b-(1<<k)+1][k])<<endl;
    }
    
    return 0;
}


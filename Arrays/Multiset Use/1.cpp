// problem link --

// https://cses.fi/problemset/task/1632

// Multiset Use

// code -- 

#include <bits/stdc++.h>
using namespace std;
#define int long long
const unsigned int M=1000000007;
#define p pair<int,int>
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    int n,k; cin>>n>>k;
    vector<vector<int> >x;
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        x.push_back({b,a});
    }
    multiset<int>ms;
    int res=0;
    for(int i=0;i<k;i++) ms.insert(0);
    sort(x.begin(),x.end());
    for(int i=0;i<n;i++){
        int st=x[i][1];
        int en=x[i][0];
        auto it = ms.upper_bound(st);
        if(it!=ms.begin()){
            --it;
            ms.erase(it);
            ms.insert(en);
            res++;
        }
    }
    cout<<res<<endl;
    return 0;
}
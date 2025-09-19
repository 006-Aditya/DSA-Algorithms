// problem link --

// https://cses.fi/problemset/task/1644

// Multiset Use

// code -- 

#include <bits/stdc++.h>
using namespace std;
#define int long long
const unsigned int M=1000000007;
#define p pair<int,int>
// 10 1 3
// 0 1 0 0 0 1 1 2 0 0
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    int n,a,b; cin>>n>>a>>b;
    vector<int>x(n+1);
    int res=-1e18;
    vector<int>pref(n+1);
    for(int i=1;i<=n;i++){
        cin>>x[i]; pref[i]=pref[i-1]+x[i];
    }
    multiset<int>ms;
    for(int i=a;i<=n;i++){
        if(i>b){
            ms.erase(ms.find(pref[i-b-1]));
        }
        ms.insert(pref[i-a]);
        int temp=pref[i]-*ms.begin();
        res=max(res,temp);
    }
    cout<<res<<endl;
    
    return 0;
}

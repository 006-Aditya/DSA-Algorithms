// problem link --

// https://leetcode.com/problems/distribute-repeating-integers/?envType=problem-list-v2&envId=bit-manipulation

// BitMasking

// code -- 

class Solution {
public:
    int n,m;
    int dp[51][1025];
    bool solve(int level, vector<int>& x, vector<int>& quantity, int mask){
        if(mask==0) return true;
        if(level==n){
            return false;
        }
        if(dp[level][mask]!=-1) return dp[level][mask];
       
        for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
            int total = 0;
            for (int i = 0; i < m; ++i) {
                if (submask & (1 << i)) {
                    total += quantity[i];
                }
            }
            if (x[level] >= total) {
                if (solve(level + 1, x, quantity, mask ^ submask)) {
                    return dp[level][mask] = true;
                }
            }
        }
        
        if(solve(level+1,x,quantity,mask)){
            return dp[level][mask]=true;
        }
        return dp[level][mask]=false;
    }
    // 1 1 2 -- 2 2
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        n=nums.size();
        m=quantity.size();
        sort(quantity.begin(),quantity.end());
        int hash[1001]={0};
        for(int i=0;i<n;i++) hash[nums[i]]++;
        vector<int>x;
        for(int i=0;i<1001;i++){
            if(hash[i]>0) x.push_back(hash[i]);
        }
        sort(x.begin(),x.end());
        n=x.size();
        int mask=(1<<m)-1;
        memset(dp,-1,sizeof(dp));
        return solve(0,x,quantity,mask);
    }
};
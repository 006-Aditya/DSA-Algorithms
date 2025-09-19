// problem link --

// https://leetcode.com/problems/maximize-score-after-n-operations/description/?envType=problem-list-v2&envId=bit-manipulation

// BitMasking

// code -- 

class Solution {
public:
    int n,cnt; 
    unordered_map<int, int>mp; 
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    int solve(vector<int>& nums, int count, int mask){
        if(count>cnt) return 0;
        if(mp.find(mask)!=mp.end()) return mp[mask];
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(mask & (1<<i)) continue;
            for(int j=i+1;j<n;j++){
                if(mask & (1<<j)) continue;
                int findGCD=gcd(nums[i],nums[j]);
                mask|=(1<<i);
                mask|=(1<<j);
                ans=max(ans,count*findGCD+solve(nums,count+1,mask));
                mask^=(1<<i);
                mask^=(1<<j);
            }
        }
        return mp[mask]=ans;
    }
    int maxScore(vector<int>& nums) {
        mp.clear();
        n=nums.size();
        cnt=n/2;
        int mask=0;
        return solve(nums,1,mask);
    }
};
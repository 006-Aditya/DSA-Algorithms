// problem link --

// https://leetcode.com/problems/range-product-queries-of-powers/description/?envType=problem-list-v2&envId=23baaszv

// Binary Exponentiation and use of mod inverse

// code -- 


class Solution {
public:
    const int M = 1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>x;
        for(int i=0;(1<<i)<=n;i++){
            if(n&(1<<i)) x.push_back(1<<i);
        }
        int m=x.size();
        vector<long long>preAns(m+1,1);
        for(int i=1;i<=m;i++){
            preAns[i]=(preAns[i-1]*x[i-1])%M;
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            long long result=(preAns[queries[i][1]+1]*modInverse(preAns[queries[i][0]],M))%M;
            ans.push_back(result);
        }
        // 1 1 2 8 64
        // 0 1 2 3 4 
        return ans;
    }

    private:
    // Function to compute the modular inverse using Fermat's Little Theorem
    long long modInverse(long long a, long long m) {
        return power(a, m - 2, m);
    }

    // Function to compute a^b % m using binary exponentiation
    long long power(long long a, long long b, long long m) {
        long long result = 1;
        while (b > 0) {
            if (b % 2 == 1) {
                result = (result * a) % m;
            }
            a = (a * a) % m;
            b /= 2;
        }
        return result;
    }
};
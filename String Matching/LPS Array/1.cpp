// problem link --

// https://leetcode.com/problems/shortest-palindrome/description/?envType=problem-list-v2&envId=rolling-hash

// LPS Array

// code -- 

class Solution {
public:
    void computeLPS(string k,vector<int>&LPS,int m){
        int len=0;
        LPS[0]=0;
        int i=1;
        while(i<m){
            if(k[i]==k[len]){
                len++;
                LPS[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=LPS[len-1];
                }else{
                    LPS[i]=0;
                    i++;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        int n=s.size();
        string reversed=s;
        reverse(reversed.begin(),reversed.end());
        string k=s+'#'+reversed;
        int m=k.size();
        vector<int>LPS(m);
        computeLPS(k,LPS,m);
        int len=LPS[m-1];
        return reversed.substr(0,n-len)+s;
    }
};
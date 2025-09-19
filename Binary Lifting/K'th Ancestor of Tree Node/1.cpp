// Binary Lifting/ Jump -- 

// Problem Link -- https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

// Code -- 

class TreeAncestor {
public:
    int parTable[50001][21];
    int logVal[50001];

    TreeAncestor(int n, vector<int>& parent) {
        memset(parTable,-1,sizeof(parTable));
        // calculate logVal
        logVal[1]=0;
        for(int i=2;i<50001;i++){
            logVal[i]=logVal[i/2]+1;
        }
        for(int i=0;i<n;i++){
            parTable[i][0]=parent[i];
        }
        // fil parent table
        for(int j=1;j<=20;j++){
            for(int i=1;i<n;i++){
                int oldPar=parTable[i][j-1];
                if(oldPar==-1) parTable[i][j]=-1;
                else parTable[i][j]=parTable[oldPar][j-1];
            }
        }
    }

    int solve(int node, int k){
        if(k==1) return parTable[node][0];

        int newK=logVal[k];
        int newPar=parTable[node][newK];
        if(newPar==-1) return -1;
        if(k-(1<<newK)==0) return newPar;
        int ans=solve(newPar,k-(1<<newK));
        return ans;
    }
    
    int getKthAncestor(int node, int k) {
        return solve(node,k);
    }
};
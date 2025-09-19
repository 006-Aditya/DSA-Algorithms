// problem link --

// https://www.geeksforgeeks.org/problems/burning-tree/1

// Burning Tree 

// code -- 


class Solution {
  public:
    void traverse(Node* root, int target, unordered_map<Node*,Node*> &par, Node* &tar){
        if(root==NULL) return;
        if(root->data==target) tar=root;
        if(root->left){
            par[root->left]=root;
            traverse(root->left,target,par,tar);
        }
        if(root->right){
            par[root->right]=root;
            traverse(root->right,target,par,tar);
        }
    }
    int minTime(Node* root, int target) {
        // code here
        unordered_set<Node*>vis;
        unordered_map<Node*,Node*> par;
        Node* tar=NULL;
        traverse(root,target,par,tar);
        queue<Node*>q;
        q.push(tar);
        int res=0;
        while(!q.empty()){
            int n=q.size();
            int flag=0;
            for(int i=0;i<n;i++){
                Node* curr=q.front();
                q.pop();
                if(vis.find(curr)==vis.end()){
                    if(curr->left){
                        q.push(curr->left);
                    }
                    if(curr->right){
                        q.push(curr->right);
                    }
                    if(par[curr]){
                        q.push(par[curr]);
                    }
                    flag=1;
                }
                vis.insert(curr);
            }
            if(flag) res++;
        }
        return res-1;
    }
};
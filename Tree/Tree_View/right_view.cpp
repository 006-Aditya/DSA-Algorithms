// problem link --

// https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1

// Right View of Binary Tree 

// code -- 


class Solution {
  public:
    vector<int> rightSide(Node *root,vector<int> &res,int level){
        // Your code here
        if(root==NULL) return res;
        if(res.size()==level) res.push_back(root->data);
        rightSide(root->right,res,level+1);
        rightSide(root->left,res,level+1);
        return res;
    }
    vector<int> rightView(Node *root){
       // Your code here
       vector<int>res;
       if(!root) return res;
       return rightSide(root,res,0);
    }
};
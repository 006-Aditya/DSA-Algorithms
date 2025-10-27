// problem link --

// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

// Left View of Binary Tree 

// code -- 


class Solution {
  public:
    vector<int> leftside(Node *root,vector<int> &res,int level){
        // Your code here
        if(root==NULL) return res;
        if(res.size()==level) res.push_back(root->data);
        leftside(root->left,res,level+1);
        leftside(root->right,res,level+1);
        return res;
    }
    vector<int> leftView(Node *root){
       // Your code here
       vector<int>res;
       if(!root) return res;
       return leftside(root,res,0);
    }
};
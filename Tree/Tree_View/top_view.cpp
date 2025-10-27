// problem link --

// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

// Top View of Binary Tree 

// code -- 


class Solution {
  public:
    vector<int> topView(Node *root){
        //Your code here
        vector<int>res;
        if(root==NULL) return res;
        map<int,int>ans;
        queue<pair<Node*,int> >q;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node* ptr=it.first;
            int level=it.second;
            if(ans.find(level)==ans.end()){
                ans[level]=ptr->data;
            }
            if(ptr->left){
                q.push({ptr->left,level-1});
            }
            if(ptr->right){
                q.push({ptr->right,level+1});
            }
        }
        for(auto it:ans){
            res.push_back(it.second);
        }
        return res;
    }
};
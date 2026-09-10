/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,int> traverse(TreeNode* root,int& res){
        // first one is for sum of this subtree 
        // 2nd one is for number of nodes of this subtree 
        if(!root)
            return {0,0};
        auto left=traverse(root->left,res);
        auto right=traverse(root->right,res);
        int total=root->val+left.first+right.first;
        int count=1+left.second+right.second;
        if(total/count==root->val)
            res++;
        return {total,count};
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
        int res=0;
        auto ans=traverse(root,res);
        return res;
        
    }
};
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
    TreeNode* height(TreeNode* node){
        if(!node) 
            return node;
        TreeNode* temp=node->left;
        node->left=node->right;
        node->right=temp;
        height(node->left);
        height(node->right);
        return node;

    }
    TreeNode* invertTree(TreeNode* root) {
        return height(root);
    }
};
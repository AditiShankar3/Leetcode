/*
[Description]
Binary Tree Level Order Traversal
https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/2099460252/

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 
Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []

 
Constraints:

  The number of nodes in the tree is in the range [0, 2000].
  -1000 <= Node.val <= 1000

[Metadata]
- Difficulty: Medium
- Topics: Tree, Breadth-First Search, Binary Tree
- Slug: binary-tree-level-order-traversal
*/

// [Solution]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);
        int currLevel=0;
        while(!q.empty()){
            int len=q.size();
            res.push_back({});
            for(int i=0;i<len;i++){
                TreeNode* node=q.front();
                q.pop();
                res[currLevel].push_back(node->val);
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
            }
            currLevel++;
        }
        return res;
    }
};
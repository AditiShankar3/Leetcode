/*
[Description]
Invert Binary Tree
https://leetcode.com/problems/invert-binary-tree/submissions/2127999750/

Given the root of a binary tree, invert the tree, and return its root.

 
Example 1:

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:

Input: root = [2,1,3]
Output: [2,3,1]

Example 3:

Input: root = []
Output: []

 
Constraints:

  The number of nodes in the tree is in the range [0, 100].
  -100 <= Node.val <= 100

[Metadata]
- Difficulty: Easy
- Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree
- Slug: invert-binary-tree
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
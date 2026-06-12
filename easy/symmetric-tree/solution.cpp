/*
[Description]
Symmetric Tree
https://leetcode.com/problems/symmetric-tree/submissions/2031001439/

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 
Example 1:

Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:

Input: root = [1,2,2,null,3,null,3]
Output: false

 
Constraints:

  The number of nodes in the tree is in the range [1, 1000].
  -100 <= Node.val <= 100

 
Follow up: Could you solve it both recursively and iteratively?

[Metadata]
- Difficulty: Easy
- Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree
- Slug: symmetric-tree
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
    bool isMirror(TreeNode* n1,TreeNode* n2){
        if(n1==NULL && n2==NULL)
            return true;
        if(n1==NULL || n2==NULL)
            return false;
        return n1->val==n2->val && isMirror(n1->left,n2->right) && isMirror(n1->right, n2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left,root->right);
    }
};
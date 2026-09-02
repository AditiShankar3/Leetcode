/*
[Description]
Subtree of Another Tree
https://leetcode.com/problems/subtree-of-another-tree/submissions/2128152120/

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

 
Example 1:

Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true

Example 2:

Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false

 
Constraints:

  The number of nodes in the root tree is in the range [1, 2000].
  The number of nodes in the subRoot tree is in the range [1, 1000].
  -104 <= root.val <= 104
  -104 <= subRoot.val <= 104

[Metadata]
- Difficulty: Easy
- Topics: Tree, Depth-First Search, String Matching, Binary Tree, Hash Function
- Slug: subtree-of-another-tree
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
    bool check(TreeNode* root,TreeNode* subRoot){
        if(root==NULL && subRoot==NULL)
            return true;
        else if(root==NULL || subRoot==NULL || root->val!=subRoot->val)
            return false;
        if(!check(root->left,subRoot->left))
            return false;
        if(!check(root->right,subRoot->right))
            return false;
        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL)
            return false;
        if(root->val==subRoot->val){
            if(check(root,subRoot))
                return true;
        }
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};
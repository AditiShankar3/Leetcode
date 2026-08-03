/*
[Description]
Binary Tree Zigzag Level Order Traversal
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/2092532011/

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 
Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []

 
Constraints:

  The number of nodes in the tree is in the range [0, 2000].
  -100 <= Node.val <= 100

[Metadata]
- Difficulty: Medium
- Topics: Tree, Breadth-First Search, Binary Tree
- Slug: binary-tree-zigzag-level-order-traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL)
            return result;
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool indi=true;
        while(!nodesQueue.empty()){
            int size=nodesQueue.size();
            vector<int> row(size);
            for(int i=0;i<size;i++){
                TreeNode* node=nodesQueue.front();
                nodesQueue.pop();
                int index=indi?i:size-1-i;
                row[index]=node->val;
                if(node->left)
                    nodesQueue.push(node->left);
                if(node->right)
                    nodesQueue.push(node->right);
            }
            indi=!indi;
            result.push_back(row);
        }
        return result;
    }
};
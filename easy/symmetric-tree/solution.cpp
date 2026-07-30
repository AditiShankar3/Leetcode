/*
[Description]
Symmetric Tree
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/2087829336/

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
    TreeNode* helper(vector<int>& nums,int left,int right){
        if(left>right)
            return NULL;
        int mid=left+(right-left)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=helper(nums,left,mid-1);
        root->right=helper(nums,mid+1,right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        /*
        To convert a sorted array to a binary search tree, we can use the following recursive algorithm:

        If the array is empty, return null.
        Find the middle element of the array and create a new node with its value.
        Recursively construct the left subtree using the left half of the array.
        Recursively construct the right subtree using the right half of the array.
        Set the left and right child of the node created in step 2 to the root of the left and right subtree respectively.
        Return the root node.
        */
        return helper(nums,0,nums.size()-1);
    }
};
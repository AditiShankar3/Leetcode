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
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int> index;
        for(int i=0;i<postorder.size();i++)
            index[postorder[i]]=i;
        return buildTree(preorder,postorder,0,preorder.size()-1,0,postorder.size()-1,index);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder, int preorderStart,int preorderEnd,int postorderStart,int postorderEnd,unordered_map<int,int>& index){
        if(preorderStart>preorderEnd || postorderStart>postorderEnd)
            return NULL;
        int val=preorder[preorderStart];
        TreeNode* root=new TreeNode(val);
        if(preorderStart == preorderEnd)
            return root;
        int left=preorder[preorderStart+1];
        int ind=index[left];
        int leftsize=ind-postorderStart+1;
        root->left=buildTree(preorder,postorder,preorderStart+1,preorderStart + leftsize,postorderStart,postorderStart+leftsize-1,index);
        root->right=buildTree(preorder,postorder,preorderStart+leftsize+1,preorderEnd,ind+1,postorderEnd-1,index);
        return root;
    }
};
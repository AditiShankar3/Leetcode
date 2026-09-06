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
        int currLev=0;
        while(!q.empty()){
            int len=q.size();
            res.push_back({});
            for(int i=0;i<len;i++){
                TreeNode* node=q.front();
                q.pop();
                res[currLev].push_back(node->val);
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
            }
            currLev++;
        }
        return res;
    }
};
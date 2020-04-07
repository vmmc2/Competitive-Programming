/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int> ans;
public:
    void auxinorder(TreeNode *root){
        if(root == NULL) return;
        auxinorder(root->left);
        ans.push_back(root->val);
        auxinorder(root->right);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        auxinorder(root);
        return ans;
    }
};

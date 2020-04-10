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
public:
    void intrav(TreeNode* root, vector<int> &ans){
        if(root == NULL) return;
        intrav(root->left, ans);
        ans.push_back(root->val);
        intrav(root->right, ans);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        intrav(root, ans);
        return ans;
    }
};

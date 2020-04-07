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
   void inorder_traversal(TreeNode *root, int k, vector<int> &jj){
        if(root == NULL) return;
        inorder_traversal(root->left, k, jj);
        jj.push_back(root->val);
        if((int)jj.size() == k) return;
        inorder_traversal(root->right, k, jj);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> jj;
        inorder_traversal(root, k, jj);
        return jj[k - 1];
    }
};

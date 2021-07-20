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
    void auxRevert(TreeNode* root){
        if(root == NULL) return;
        
        auxRevert(root->left);
        auxRevert(root->right);
        TreeNode* aux;
        aux = root->left;
        root->left = root->right;
        root->right = aux;
        
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        auxRevert(root);
        return root;
    }
};

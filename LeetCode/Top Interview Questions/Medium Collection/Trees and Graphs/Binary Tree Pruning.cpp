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
    TreeNode* auxPrune(TreeNode* root){
        if(root == NULL){
            return NULL;
        }
        root->left = auxPrune(root->left);
        root->right = auxPrune(root->right);
        
        if(root->left == NULL && root->right == NULL && root->val == 0){
            return NULL;
        }
        return root;
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        root = auxPrune(root);
        return root;
    }
};

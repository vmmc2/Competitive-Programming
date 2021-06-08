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
    TreeNode* auxDeletion(TreeNode* root, int target){
        if(root->left == NULL && root->right == NULL){
            if(root->val == target) return NULL;
        }
        if(root->left != NULL){
            root->left = auxDeletion(root->left, target);
        }
        if(root->right != NULL){
            root->right = auxDeletion(root->right, target);
        }
        if(root->left == NULL && root->right == NULL){
            if(root->val == target) return NULL;
        }
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root == NULL) return root;
        
        root = auxDeletion(root, target);
        return root;
    }
};

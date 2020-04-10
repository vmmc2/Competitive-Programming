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
    bool checksym(TreeNode *esquerdo, TreeNode *direito){
        if(esquerdo == NULL && direito == NULL) return true;
        if(esquerdo == NULL && direito != NULL) return false;
        if(esquerdo != NULL && direito == NULL) return false;
        if(esquerdo->val != direito->val) return false;
        return checksym(esquerdo->left, direito->right) && checksym(esquerdo->right, direito->left);
        
    }
    bool isSymmetric(TreeNode* root) {
        //Solving for the base case:
        if(root == NULL) return true; //empty tree.
        if(root->left == NULL && root->right == NULL) return true; //tree with just one node.
        return checksym(root->left, root->right);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <cmath>

class Solution {
public:
    bool auxiliar(TreeNode *root, long int minimo, long int maximo){
        if(root == NULL) return true;
        if((long int)(root->val) <= minimo || (long int)(root->val) >= maximo) return false;
        return auxiliar(root->left, minimo, root->val) && auxiliar(root->right, root->val, maximo);
    }
    bool isValidBST(TreeNode* root) {
        return auxiliar(root, pow(2,32)*(-1), pow(2,32) - 1);
    }
};

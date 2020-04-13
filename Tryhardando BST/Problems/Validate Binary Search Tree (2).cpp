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
    bool validate(TreeNode* root, long int min_val, long int max_val){
        if(root == NULL) return true;
        if(root->val <= min_val || root->val >= max_val) return false;
        return validate(root->left, min_val, root->val) && validate(root->right, root->val, max_val);
    }
    bool isValidBST(TreeNode* root) {
        //As always, we treat the conner cases first. They are: an empty BST and a BST with just one node.
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        return validate(root, pow(2,32)*(-1), pow(2,31) + 1);
    }
};

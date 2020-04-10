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
    bool valid(TreeNode *root, long int min_val, long int max_val){
        if(root == NULL) return true;
        if(root->val <= min_val || root->val >= max_val) return false;
        if(!valid(root->left, min_val, root->val)) return false;
        if(!valid(root->right, root->val, max_val)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        //check and treat the conner cases:
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        return valid(root, pow(2,31)*(-2), pow(2,31) + 2);
    }
};

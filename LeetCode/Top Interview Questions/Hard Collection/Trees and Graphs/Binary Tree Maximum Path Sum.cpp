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
#include <cmath>

class Solution {
public:
    int maxValue = pow(2,31)*(-1);
    
    int pathSum(TreeNode *node){
        if(node == NULL) return 0;
        int left = max(0, pathSum(node->left));
        int right = max(0, pathSum(node->right));
        maxValue = max(maxValue, left + right + node->val);
        return max(left, right) + node->val;
    }
    int maxPathSum(TreeNode* root) {
        pathSum(root);
        return maxValue;
    }
};

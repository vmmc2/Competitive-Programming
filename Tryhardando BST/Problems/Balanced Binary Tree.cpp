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

struct BalancedStatus{
    bool isBalanced;
    int height;
    BalancedStatus(bool x, int y): isBalanced(x), height(y) {}
};

class Solution {
public:
    BalancedStatus* checkbalanced(TreeNode *root){
        if(root == NULL){
            return new BalancedStatus(true, -1);
        }
        BalancedStatus *leftresult = checkbalanced(root->left);
        if(!leftresult->isBalanced){
            return leftresult;
        }
        BalancedStatus *rightresult = checkbalanced(root->right);
        if(!rightresult->isBalanced){
            return rightresult;
        }
        bool subtreebalanced;
        if(abs(leftresult->height - rightresult->height) <= 1){
            subtreebalanced = true;
        }else{
            subtreebalanced = false;
        }
        int subtreeheight = 1 + max(leftresult->height, rightresult->height);
        return new BalancedStatus(subtreebalanced, subtreeheight);
    }
    
    bool isBalanced(TreeNode* root) {
        return checkbalanced(root)->isBalanced;
    }
};

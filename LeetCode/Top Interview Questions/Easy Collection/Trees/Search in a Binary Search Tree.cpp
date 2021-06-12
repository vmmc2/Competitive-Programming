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
    TreeNode* findInBST(TreeNode* root, int val){
        if(root == NULL){
            return NULL;
        }
        if(root->val == val){
            return root;
        }else if(val < root->val){
            return findInBST(root->left, val);
        }
        return findInBST(root->right, val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return findInBST(root, val);
    }
};

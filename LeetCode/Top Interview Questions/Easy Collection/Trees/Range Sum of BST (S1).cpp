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
    int findSum(TreeNode* root, int low, int high){
        if(root->left == NULL && root->right == NULL){
            if(low <= root->val && root->val <= high) return root->val;
            else return 0;
        }
        int current = 0, left1 = 0, right1 = 0;
        if(low <= root->val && root->val <= high){
            current = root->val;
        }
        if(root->left != NULL){
            left1 = findSum(root->left, low, high);
        }
        if(root->right != NULL){
            right1 = findSum(root->right, low, high);
        }
        return current + left1 + right1;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return findSum(root, low, high);
    }
};

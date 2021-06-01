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
    void find_height(TreeNode *root, int& maxDeep, int currentDeep){
        maxDeep = max(maxDeep, currentDeep);
        if(root->left == NULL && root->right == NULL){
            return;
        }
        if(root->left != NULL){
            find_height(root->left, maxDeep, currentDeep + 1);
        }
        if(root->right != NULL){
            find_height(root->right, maxDeep, currentDeep + 1);
        }
        return;
    }
    void get_sum_leaves(TreeNode *root, int& answer, int& maxDeep, int currentDeep){
        if(root->left == NULL && root->right == NULL){
            if(currentDeep == maxDeep){
                answer += root->val;
            }
        }
        if(root->left != NULL){
            get_sum_leaves(root->left, answer, maxDeep, currentDeep + 1);
        }
        if(root->right != NULL){
            get_sum_leaves(root->right, answer, maxDeep, currentDeep + 1);
        }
        return;
    }
    int deepestLeavesSum(TreeNode* root) {
        int answer = 0;
        if(root == NULL) return answer;
        if(root->left == NULL && root->right == NULL) return root->val;
        
        int maxDeep = 0;
        int currentDeep = 0;
        find_height(root, maxDeep, currentDeep);
        
        get_sum_leaves(root, answer, maxDeep, currentDeep);
        
        return answer;
    }
};

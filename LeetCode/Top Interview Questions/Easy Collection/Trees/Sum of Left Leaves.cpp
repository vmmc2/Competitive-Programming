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
    void auxTraversal(TreeNode* root, int& answer, int cameFromLeft){
        if(root->left == NULL && root->right == NULL && cameFromLeft == 1){
            answer += root->val;
            return;
        }
        if(root->left != NULL){
            auxTraversal(root->left, answer, 1);
        }
        if(root->right != NULL){
            auxTraversal(root->right, answer, 0);
        }
        return;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int answer = 0;
        auxTraversal(root, answer, 0);
        return answer;
    }
};

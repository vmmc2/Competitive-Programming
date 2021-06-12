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
    void pathSumAux(TreeNode* root, int &targetSum, int currentSum, bool &answer){
        if(root->left == NULL && root->right == NULL){ //im in a leaf.
            currentSum += root->val;
            if(currentSum == targetSum){
                answer = true;
            }
            return;
        }
        if(root->left != NULL){
            pathSumAux(root->left, targetSum, currentSum + root->val, answer);
            if(answer == true) return;
        }
        if(root->right != NULL){
            pathSumAux(root->right, targetSum, currentSum + root->val, answer);
            if(answer == true) return;
        }
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool answer = false;
        int currentSum = 0;
        
        if(root == NULL) return answer;
        
        pathSumAux(root, targetSum, currentSum, answer);
        
        return answer;
    }
};

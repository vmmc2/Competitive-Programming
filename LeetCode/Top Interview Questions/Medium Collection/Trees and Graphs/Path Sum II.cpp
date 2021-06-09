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
    void dfs(TreeNode* root, int targetSum, int currentSum, vector<vector<int>> &answer, vector<int> path){
        if(root->left == NULL && root->right == NULL){
            currentSum += root->val;
            path.push_back(root->val);
            
            if(currentSum == targetSum){
                answer.push_back(path);
            }
            return;
        }
        
        currentSum += root->val;
        path.push_back(root->val);
        
        if(root->left != NULL){
            dfs(root->left, targetSum, currentSum, answer, path);
        }
        if(root->right != NULL){
            dfs(root->right, targetSum, currentSum, answer, path);    
        }
        
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int currentSum = 0;
        vector<vector<int>> answer;
        vector<int> path;
        
        if(root == NULL) return answer;
        
        dfs(root, targetSum, currentSum, answer, path);
        
        return answer;
    }
};

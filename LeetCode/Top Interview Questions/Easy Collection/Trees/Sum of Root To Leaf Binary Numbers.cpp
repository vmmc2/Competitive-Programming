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
    void aux(TreeNode* root, vector<int> &currentPath, int& answer){
        if(root->left == NULL && root->right == NULL){
            currentPath.push_back(root->val);
            reverse(currentPath.begin(), currentPath.end());
            int number = 0;
            int power = 1;
            for(int i = 0; i < (int)currentPath.size(); i++){
                number += currentPath[i]*power;
                power = power * 2;
            }
            answer += number;
            reverse(currentPath.begin(), currentPath.end());
            currentPath.pop_back();
            return;
        }
        currentPath.push_back(root->val);
        if(root->left != NULL){
            aux(root->left, currentPath, answer);
        }
        if(root->right != NULL){
            aux(root->right, currentPath, answer);
        }
        currentPath.pop_back();
        return;
    }
    int sumRootToLeaf(TreeNode* root) {
        int answer = 0;
        vector<int> currentPath;
        
        if(root == NULL) return answer;
        
        aux(root, currentPath, answer);
        return answer;
    }
};

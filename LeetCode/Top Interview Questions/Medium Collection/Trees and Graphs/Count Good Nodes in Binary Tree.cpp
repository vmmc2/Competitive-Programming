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
    void findNumGNodes(TreeNode* root, int current_max, int& answer){
        if(root == NULL) return;
        
        if(root->val >= current_max){
            answer++;
        }
        findNumGNodes(root->left, max(current_max, root->val), answer);
        findNumGNodes(root->right, max(current_max, root->val), answer);
        
        return;
    }
    int goodNodes(TreeNode* root) {
        int answer = 0;
        if(root == NULL){
            return answer;
        }
        
        int current_max = root->val;
        findNumGNodes(root, current_max, answer);
        
        return answer;
    }
};

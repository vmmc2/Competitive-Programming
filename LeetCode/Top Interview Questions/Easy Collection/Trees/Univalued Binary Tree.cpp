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
    void checkUnivalTree(TreeNode* root, bool &answer, int unival){
        if(root == NULL){
            return;
        }
        if(root->val != unival){
            answer = false;
            return;
        }
        checkUnivalTree(root->left, answer, unival);
        if(answer == false) return;
        checkUnivalTree(root->right, answer, unival);
        
        return;
    }
    bool isUnivalTree(TreeNode* root) {
        bool answer = true;
        int unival = root->val;
        
        checkUnivalTree(root, answer, unival);
        
        return answer;
    }
};

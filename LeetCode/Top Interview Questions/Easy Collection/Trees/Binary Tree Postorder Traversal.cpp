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
    void auxTraversal(TreeNode* root, vector<int> &answer){
        if(root == NULL) return;
        auxTraversal(root->left, answer);
        auxTraversal(root->right, answer);
        answer.push_back(root->val);
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> answer;
        auxTraversal(root, answer);
        
        return answer;
    }
};

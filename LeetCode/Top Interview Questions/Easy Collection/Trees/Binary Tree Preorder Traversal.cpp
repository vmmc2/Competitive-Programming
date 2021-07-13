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
        answer.push_back(root->val);
        auxTraversal(root->left, answer);
        auxTraversal(root->right, answer);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        auxTraversal(root, answer);
        return answer;
    }
};

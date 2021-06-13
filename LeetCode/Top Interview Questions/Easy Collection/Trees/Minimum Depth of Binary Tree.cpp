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
    void treeTraversal(TreeNode* root, int currentDepth, int &answer){
        if(root->left == NULL && root->right == NULL){
            answer = min(answer, currentDepth);
            return;
        }
        if(root->left != NULL){
            treeTraversal(root->left, currentDepth + 1, answer);
        }
        if(root->right != NULL){
            treeTraversal(root->right, currentDepth + 1, answer);
        }
        return;
    }
    int minDepth(TreeNode* root) {
        int answer = 10000007;
        int currentDepth = 1;
        
        if(root == NULL) return 0;
        
        treeTraversal(root, currentDepth, answer);
        
        return answer;
    }
};

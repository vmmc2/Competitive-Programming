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
    TreeNode* answer;
    TreeNode* insertNode(TreeNode* root, int val){;
        if(root == NULL){
            return new TreeNode(val);
        }else{
            root->right = insertNode(root->right, val);
        }
        return root;
    }
    void inorderTraversal(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorderTraversal(root->left);
        answer = insertNode(answer, root->val);
        inorderTraversal(root->right);
        
        return;
    }
    TreeNode* increasingBST(TreeNode* root) {
        answer = NULL;
        inorderTraversal(root);
        return answer;
    }
};

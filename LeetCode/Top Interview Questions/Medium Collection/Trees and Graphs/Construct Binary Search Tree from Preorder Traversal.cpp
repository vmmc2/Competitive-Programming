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
    TreeNode* insertNode(TreeNode* root, int value){
        if(root == NULL){
            return new TreeNode(value);
        }
        if(value < root->val){
            root->left = insertNode(root->left, value);
        }else{
            root->right = insertNode(root->right, value);
        }
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for(int i = 0; i < (int)preorder.size(); i++){
            root = insertNode(root, preorder[i]);
        }
        return root;
    }
};

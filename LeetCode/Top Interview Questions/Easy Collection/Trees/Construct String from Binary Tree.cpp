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
    string buildString(TreeNode* root, int layer, bool isLeft){
        if(root == NULL && isLeft == true) return "()";
        else if(root == NULL && isLeft == false) return "";
        else if(layer == 1 && root->left == NULL && root->right == NULL){
            return to_string(root->val);
        }
        else if(layer != 1 && root->left == NULL && root->right == NULL){
            return "(" + to_string(root->val) + ")";
        }
        else if(layer == 1){
            return to_string(root->val) + buildString(root->left, layer + 1, true) + buildString(root->right, layer + 1, false);
        }
        //if layer > 1
        return "(" + to_string(root->val) + buildString(root->left, layer + 1, true) + buildString(root->right, layer + 1, false) + ")";
        
    }
    string tree2str(TreeNode* root) {
        return buildString(root, 1, false);
    }
};

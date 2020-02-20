/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int maximum = 1;
int counter = 1;

class Solution {
public:
    void travessy(TreeNode *root){
        if(root->left != NULL){
            counter++;
            maximum = max(maximum, counter);
            travessy(root->left);
            counter--;
        }
        if(root->right != NULL){
            counter++;
            maximum = max(maximum, counter);
            travessy(root->right);
            counter--;
        }
        return;
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        travessy(root);
        return maximum;
    }
};

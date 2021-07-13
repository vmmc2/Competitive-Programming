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
    bool checkTree(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL){
            return true;
        }else if(p != NULL && q != NULL){
            if(p->val != q->val) return false;
        }else{
            return false;
        }
        return checkTree(p->left, q->left) && checkTree(p->right, q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checkTree(p, q);
    }
};

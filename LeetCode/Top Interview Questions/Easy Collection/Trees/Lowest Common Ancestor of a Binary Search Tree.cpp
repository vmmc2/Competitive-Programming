/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* findNode(TreeNode* root, int minimo, int maximo){
        if(minimo < root->val && root->val < maximo){
            return root;
        }else if(minimo < root->val && maximo < root->val){
            return findNode(root->left, minimo, maximo);
        }else if(root->val < minimo && root->val < maximo){
            return findNode(root->right, minimo, maximo);
        }else if(minimo < root->val && root->val == maximo) return root;
        else return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int minimo = min(p->val, q->val);
        int maximo = max(p->val, q->val);
        return findNode(root, minimo, maximo);
    }
};

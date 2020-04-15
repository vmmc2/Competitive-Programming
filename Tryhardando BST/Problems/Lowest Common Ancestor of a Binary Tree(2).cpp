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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return root;
        if(root->val == p->val || root->val == q->val) return root;
        TreeNode *esquerda = lowestCommonAncestor(root->left, p, q);
        TreeNode *direita = lowestCommonAncestor(root->right, p, q);
        if(esquerda == NULL) return direita;
        if(direita == NULL) return esquerda;
        return root;
    }
};

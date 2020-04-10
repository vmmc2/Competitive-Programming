/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
Quando estamos falando em Binary Search Tree (BST) e queremos uma travessia de maneira ordenada ou entao buscamos
o K-esimo menor elemento, devemos pensar imediatamente em um inorder traversal, pois, com ela, iteramos sobre todos os nodes de nossa BST de forma ordenada/ascendente.
*/
class Solution {
public:
    void inorder_traversal(TreeNode *root, vector<int> &ans, int k){
        if(root == NULL) return;
        inorder_traversal(root->left, ans, k);
        if((int)ans.size() == k) return;
        ans.push_back(root->val);
        inorder_traversal(root->right, ans, k);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorder_traversal(root, ans, k);
        return ans[k - 1];
    }
};

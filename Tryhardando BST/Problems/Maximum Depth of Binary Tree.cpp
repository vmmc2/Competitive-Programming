/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <cmath>
#include <stack>

class Solution {
public:
    void traversal(TreeNode *root, int &maximum, stack<int> &data){
        if(root == NULL) return;
        data.push(root->val);
        maximum = max(maximum,(int)data.size());
        traversal(root->left, maximum, data);
        traversal(root->right, maximum, data);
        data.pop();
        return;
    }
    int maxDepth(TreeNode* root) {
        //conner case: we receive an empty tree in the input, so we must return 0 ? yes!
        if(root == NULL) return 0;
        //another conner case in which we receive a tree with just one node. In this case, we must return 1!
        if(root->left == NULL && root->right == NULL) return 1;
        int maximum = 1;
        stack<int> data;
        traversal(root, maximum, data);
        return maximum;
    }
};

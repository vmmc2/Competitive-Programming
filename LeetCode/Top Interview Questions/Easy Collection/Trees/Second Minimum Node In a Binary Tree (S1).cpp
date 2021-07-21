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
    void treeTraversal(TreeNode* root, set<int> &values){
        if(root == NULL) return;
        
        treeTraversal(root->left, values);
        values.insert(root->val);
        treeTraversal(root->right, values);
        
        return;
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int> values;
        treeTraversal(root, values);
        
        if(values.size() == 1) return -1;
        
        set<int>::iterator it = values.begin();
        it++;
        
        return *it;
        
    }
};

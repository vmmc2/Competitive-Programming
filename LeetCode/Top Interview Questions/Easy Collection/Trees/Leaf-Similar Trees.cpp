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
    void getLeafValueSequence(TreeNode* root, vector<int> &lfv){
        if(root->left == NULL && root->right == NULL){
            lfv.push_back(root->val);
            return;
        }
        if(root->left != NULL){
            getLeafValueSequence(root->left, lfv);
        }
        if(root->right != NULL){
            getLeafValueSequence(root->right, lfv);
        }
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> lfv1;
        vector<int> lfv2;
        
        if(root1 != NULL){
            getLeafValueSequence(root1, lfv1);    
        }
        if(root2 != NULL){
            getLeafValueSequence(root2, lfv2);       
        }
        
        if((int)lfv1.size() != lfv2.size()) return false;
        for(int i = 0; i < (int)lfv1.size(); i++){
            if(lfv1[i] != lfv2[i]) return false;
        }
        return true;
    }
};

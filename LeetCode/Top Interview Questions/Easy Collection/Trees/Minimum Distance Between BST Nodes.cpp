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
    void inorderTraversal(TreeNode* root, vector<int> &values){
        if(root == NULL) return;
        
        inorderTraversal(root->left, values);
        values.push_back(root->val);
        inorderTraversal(root->right, values);
        
        return;
    }
    int minDiffInBST(TreeNode* root) {
        //ideia: fazer traversia inorder guardando num vector e depois percorre o vector para achar a menor diferenca
        vector<int> values;
        inorderTraversal(root, values);
        
        int answer = values.back() - values[0];
        for(int i = 1; i < (int)values.size(); i++){
            answer = min(answer, values[i] - values[i - 1]);
        }
        return answer;
    }
};

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
    void inorderTraversal(TreeNode* root, vector<int> &inorder){
        if(root == NULL) return;
        
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
        
        return;
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> answer;
        vector<int> inorder;
        int maxFrequency = -1;
        map<int,int> frequency;
        
        inorderTraversal(root, inorder);
        
        for(int i = 0; i < (int)inorder.size(); i++){
            frequency[inorder[i]]++;
        }
        for(map<int,int>::iterator it = frequency.begin(); it != frequency.end(); it++){
            maxFrequency = max(maxFrequency, it->second);
        }
        for(map<int,int>::iterator it = frequency.begin(); it != frequency.end(); it++){
            if(it->second == maxFrequency){
                answer.push_back(it->first);
            }
        }
        
        return answer;
    }
};

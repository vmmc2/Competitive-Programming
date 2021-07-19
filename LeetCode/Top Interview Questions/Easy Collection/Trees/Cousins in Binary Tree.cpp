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
    void findNode(TreeNode* root, int target, int level, TreeNode* parent, pair<TreeNode*,int> &pNodeLevel){
        if(root == NULL) return;
        if(root->val == target){
            pNodeLevel.first = parent;
            pNodeLevel.second = level;
            return;
        }
        findNode(root->left, target, level + 1, root, pNodeLevel);
        if(pNodeLevel.second != -1) return;
        findNode(root->right, target, level + 1, root, pNodeLevel);
        return;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        bool answer = false;
        pair<TreeNode*,int> pNodeLevelX(NULL, -1), pNodeLevelY(NULL, -1);
        
        findNode(root, x, 0, NULL, pNodeLevelX);
        findNode(root, y, 0, NULL, pNodeLevelY);
        
        if(pNodeLevelX.second == pNodeLevelY.second && pNodeLevelX.first != pNodeLevelY.first){
            answer = true;
        }
        
        return answer;
    }
};

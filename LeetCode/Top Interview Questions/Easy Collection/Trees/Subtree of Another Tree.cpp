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
    bool checkEquality(TreeNode* root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL) return true;
        if(root == NULL && subRoot != NULL) return false;
        if(root != NULL && subRoot == NULL) return false;
        if(root != NULL && subRoot != NULL && root->val == subRoot->val){
            return checkEquality(root->left, subRoot->left) && checkEquality(root->right, subRoot->right);
        }
        return false;
    }
    void findWhereBegin(TreeNode* root, TreeNode* subRoot, bool& answer){
        if(root == NULL) return;
        findWhereBegin(root->left, subRoot, answer);
        //if(answer == true) return;
        if(root->val == subRoot->val && checkEquality(root, subRoot) == true){
            answer = true;
            return;
        }
        findWhereBegin(root->right, subRoot, answer);
        
        return;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool answer = false;
        findWhereBegin(root, subRoot, answer);
        
        return answer;
    }
};

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
    void find_answer(TreeNode* root, int& answer, TreeNode* parent, TreeNode* grandparent){
        if(root->left == NULL && root->right == NULL){
            if(grandparent != NULL && (grandparent->val) % 2 == 0){
                answer += root->val;
            }
            return;
        }
        if(grandparent != NULL && (grandparent->val) % 2 == 0){
            answer += root->val;
        }
        grandparent = parent;
        parent = root;
        if(root->left != NULL){
            find_answer(root->left, answer, parent, grandparent);
        }
        if(root->right != NULL){
            find_answer(root->right, answer, parent, grandparent);
        }
        return;
    }
    int sumEvenGrandparent(TreeNode* root) {
        if(root == NULL) return 0;
        
        int answer = 0;
        find_answer(root, answer, NULL, NULL);
        
        return answer;
    }
};

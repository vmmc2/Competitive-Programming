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
    int findDiameterofBinaryTree(TreeNode* root, int& answer){
        if(root == NULL){
            return 0;
        }
        int auxLeft = findDiameterofBinaryTree(root->left, answer);
        int auxRight = findDiameterofBinaryTree(root->right, answer);
        answer = max(answer, auxLeft + auxRight);
        return (max(auxLeft, auxRight) + 1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int answer = 0;
        findDiameterofBinaryTree(root, answer);
        return answer;
    }
};

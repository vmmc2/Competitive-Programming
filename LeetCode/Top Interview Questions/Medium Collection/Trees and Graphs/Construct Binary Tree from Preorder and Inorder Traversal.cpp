/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(int preStart, int inStart, int inEnd, vector<int> &preorder, vector<int> &inorder){
        //base case..
        if(preStart > (int)preorder.size() - 1 || inStart > inEnd){
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inIndex = 0; //current index of our root in inorder;
        for(int i = inStart; i <= inEnd; i++){
            if(inorder[i] == root->val){
                inIndex = i;
            }
        }
        root->left = helper(preStart + 1, inStart, inIndex - 1, preorder, inorder);
        root->right = helper(preStart + inIndex - inStart + 1, inIndex + 1, inEnd, preorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //conner case...
        if((int)preorder.size() == 0 && (int)inorder.size() == 0) return NULL;
        //now treating the general cases.
        return helper(0, 0, (int)inorder.size() - 1, preorder, inorder);
    }
};

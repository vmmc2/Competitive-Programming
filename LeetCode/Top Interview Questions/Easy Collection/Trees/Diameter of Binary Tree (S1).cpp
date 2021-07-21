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
struct SpecialTreeNode{
    int val;
    int leftsize, rightsize;
    int maxDiameter;
    SpecialTreeNode* left;
    SpecialTreeNode* right;
    SpecialTreeNode(int x) : val(x), leftsize(0), rightsize(0), maxDiameter(0), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    SpecialTreeNode* createSpecialTree(TreeNode* root){
        if(root == NULL) return NULL;
        
        SpecialTreeNode* current = new SpecialTreeNode(root->val);
        current->left = createSpecialTree(root->left);
        current->right = createSpecialTree(root->right);
        
        return current;
    }
    int buildSpecialTree(SpecialTreeNode* nroot){
        if(nroot == NULL) return 0;
        
        nroot->leftsize = buildSpecialTree(nroot->left);
        nroot->rightsize = buildSpecialTree(nroot->right);
        nroot->maxDiameter = nroot->leftsize + nroot->rightsize;
        return (max(nroot->leftsize, nroot->rightsize) + 1);
    }
    void traversalSpecialTree(SpecialTreeNode* nroot, int& answer){
        if(nroot == NULL) return;
        
        traversalSpecialTree(nroot->left, answer);
        answer = max(answer, nroot->maxDiameter);
        traversalSpecialTree(nroot->right, answer);
        
        return;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int answer = -1;
        SpecialTreeNode* nroot = NULL;
        
        nroot = createSpecialTree(root);
        
        buildSpecialTree(nroot);
        traversalSpecialTree(nroot, answer);
        
        return answer;
    }
};

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

struct TiltTreeNode{
    int val, tiltVal;
    TiltTreeNode* left;
    TiltTreeNode* right;
    TiltTreeNode(int vl, int tvl) : val(vl), tiltVal(tvl), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TiltTreeNode* createTiltTree(TreeNode* root){
        if(root == NULL) return NULL;
        
        TiltTreeNode* current = new TiltTreeNode(root->val, -10);
        current->left = createTiltTree(root->left);
        current->right = createTiltTree(root->right);
        
        return current;
    }
    pair<int,int> tiltTraversalBuild(TiltTreeNode* root){
        if(root->left == NULL && root->right == NULL){
            root->tiltVal = 0;
            return {root->val, root->val};
        }
        pair<int,int> curr;
        pair<int,int> leftval(0, 0), rightval(0, 0);
        if(root->left != NULL){
            leftval = tiltTraversalBuild(root->left);
        }
        if(root->right != NULL){
            rightval = tiltTraversalBuild(root->right);
        }
        curr.first = root->val + leftval.first + rightval.first;
        curr.second = abs(leftval.first - rightval.first);
        root->tiltVal = curr.second;
        return curr;
    }
    void findTiltTreeSum(TiltTreeNode* root, int& answer){
        if(root == NULL) return;
        
        answer += root->tiltVal;
        findTiltTreeSum(root->left, answer);
        findTiltTreeSum(root->right, answer);
        
        return;
    }
    int findTilt(TreeNode* root) {
        int answer = 0;
        if(root == NULL) return answer;
        
        TiltTreeNode* troot = createTiltTree(root);
        tiltTraversalBuild(troot);
        findTiltTreeSum(troot, answer);
        
        return answer;
    }
};

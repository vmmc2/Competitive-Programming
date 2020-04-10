#include <bits/stdc++.h>
#include <sstream>
#include <cmath>

using namespace std;

/**
 * Definition for a Binary Tree Node
 * struct TreeNode{
 *   int val;
 *   struct TreeNode *left;
 *   struct TreeNode *right;
 *   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
*/

class Solution{
public:
    void inordertraversal(struct TreeNode *root, struct TreeNode* &target, int &flag, struct TreeNode* &insuc){
        if(root == NULL) return;
        inordertraversal(root->left, target, flag, insuc);
        if(flag == 2) return;
        if(flag == 1){
            insuc = root;
            flag = 2;
            return;
        }
        if(root == target){ //achei o node que eu estava procurando.
            flag = 1;
        }
        inordertraversal(root->right, target, flag, insuc);
        return;
    }
    struct TreeNode* inorderSucessor(struct TreeNode *root, struct TreeNode *target){
        structNode* insuc;
        int flag = 0;
        inordertraversal(root, target, flag, insuc);
        return insuc;
    }    
}

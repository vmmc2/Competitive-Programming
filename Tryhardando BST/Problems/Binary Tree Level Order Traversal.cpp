/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 /* IT WORKS JUST LIKE A BFS*/
#include <queue>

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans; // treating the conner case in which we receive an empty tree.
        
        queue<TreeNode*> fila;
        fila.push(root);
        while(!fila.empty()){
            vector<int> pseudo;
            int tam = (int)fila.size();
            for(int i = 1; i <= tam; i++){
                TreeNode *davez = fila.front();
                fila.pop();
                pseudo.push_back(davez->val);
                if(davez->left != NULL){
                    fila.push(davez->left);
                }
                if(davez->right != NULL){
                    fila.push(davez->right);
                }
            }
            ans.push_back(pseudo);
            
        }
        return ans;
    }
};

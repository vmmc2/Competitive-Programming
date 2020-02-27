#include <cmath>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        TreeNode *aux;
        queue<TreeNode *> fila;
        vector<vector<int>> finale;
        fila.push(root);
        if(root == NULL){
            return finale;
        }
        while(!fila.empty()){
            vector<int> pseudo;
            int layersize = (int)fila.size(); //isso aqui vai me dizer a quantidade de caras que eu tenho
            //na minha layer(nivel ou profundidade) atual.
            for(int i = 1; i <= layersize; i++){
                aux = fila.front();
                fila.pop();
                if(aux != NULL){
                    pseudo.push_back(aux->val);
                }
                if(aux->left != NULL){
                    fila.push(aux->left);
                }
                if(aux->right != NULL){
                    fila.push(aux->right);
                }
            }
            finale.push_back(pseudo);
        }
        return finale;
    }
};

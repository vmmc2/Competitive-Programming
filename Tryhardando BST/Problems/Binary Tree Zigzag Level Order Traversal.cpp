/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
OBSERVACAO IMPORTANTE SOBRE O PROBLEMA: Perceba que a cada camada da BST, a gente inverte a ordem de retirada
dos nodes da queue. Ou seja, a gente precisa de uma estrutura de dados que suporte insercao e remocao tanto do fim como do inicio em tempo O(1).
Solucao? Usar um deque de C++
*/

#include <deque>

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        //treating conner case: empty binary tree.
        if(root == NULL) return ans;
        deque<TreeNode*> fila;
        fila.push_back(root);
        int flag = 1;
        //se flag for impar, faco a retirada dos elementos da esquerda para a direita.
        //se flag for par, faco a retirada dos elementos da direita para a esquerda.
        while(!fila.empty()){
            int tam = (int)fila.size();
            vector<int> pseudo;
            for(int i = 1; i <= tam; i++){
                if(flag % 2 == 1){ //impar, retiro da esquerda para direita.
                    TreeNode *temp = fila.front();
                    fila.pop_front();
                    pseudo.push_back(temp->val);
                    if(temp->left != NULL){
                        fila.push_back(temp->left);
                    }
                    if(temp->right != NULL){
                        fila.push_back(temp->right);
                    }
                }else{ //par, retiro da direita para a esquerda.
                    TreeNode *temp = fila.back();
                    fila.pop_back();
                    pseudo.push_back(temp->val);
                    if(temp->right != NULL){
                        fila.push_front(temp->right);
                    }
                    if(temp->left != NULL){
                        fila.push_front(temp->left);
                    }
                }
            }
            ans.push_back(pseudo);
            flag++;
        }
        return ans;
    }
};

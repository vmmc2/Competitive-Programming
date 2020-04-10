/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

/*
Observacao: Perceba que nessa questao, eu estou fazendo a ligacao entre os nodes que estao no mesmo level/nivel/layer. Isso sugere que eu devo realizar uma travesia por nivel (BFS) na minha BST.
*/

#include <queue>

class Solution {
public:
    Node* connect(Node* root) {
        //Treating the conner case in which the tree is empty.
        if(root == NULL) return root;
        //Treating another conner case in which the given tree has only one node.
        if(root->left == NULL && root->right == NULL){
            root->next = NULL;
            return root;
        }
        
        //general case
        queue<Node*> fila;
        fila.push(root);
        while(!fila.empty()){
            int tam = (int)fila.size();
            for(int i = 1; i <= tam; i++){
                Node *temp = fila.front();
                fila.pop();
                if(tam == 1){ //caso em que eu to na raiz. O next tem que apontar para NULL por definicao.
                    temp->next = NULL;
                    if(temp->left != NULL){
                        fila.push(temp->left);
                    }
                    if(temp->right != NULL){
                        fila.push(temp->right);
                    }
                    continue;
                }
                if(i < tam){
                    temp->next = fila.front();
                    if(temp->left != NULL){
                        fila.push(temp->left);
                    }
                    if(temp->right != NULL){
                        fila.push(temp->right);
                    }
                }else if(i == tam){
                    temp->next = NULL;
                    if(temp->left != NULL){
                        fila.push(temp->left);
                    }
                    if(temp->right != NULL){
                        fila.push(temp->right);
                    }
                }
            }
        }
        return root;
    }
};

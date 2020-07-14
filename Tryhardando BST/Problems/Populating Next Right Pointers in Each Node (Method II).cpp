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
#include <queue>

class Solution {
public:
    Node* connect(Node* root) {
        //Treating the corner cases first
        if(root == NULL){
            return root;
        }
        //Solving the problem for the general cases...
        queue<Node*> fila;
        fila.push(root);
        while(!fila.empty()){
            int tam = fila.size();
            for(int i = 1; i <= tam; i++){
                if(tam == 1){ //I am in the first level of the BST. This means that I can instantly put NULL.
                    Node* temp = fila.front();
                    temp->next = NULL;
                    fila.pop();
                    if(temp->left != NULL){
                        fila.push(temp->left);
                    }
                    if(temp->right != NULL){
                        fila.push(temp->right);
                    }
                    continue;
                }
                if(i < tam){
                    Node* temp = fila.front();
                    fila.pop();
                    temp->next = fila.front();
                    if(temp->left != NULL){
                        fila.push(temp->left);
                    }
                    if(temp->right != NULL){
                        fila.push(temp->right);
                    }
                }
                else if(i == tam){
                    Node* temp = fila.front();
                    fila.pop();
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

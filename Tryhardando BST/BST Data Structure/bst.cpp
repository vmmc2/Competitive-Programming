#include <bits/stdc++.h>
#include <sstream>
#include <cmath>

using namespace std;

struct node{
  int data;
  struct node *left;
  struct node *right;
  node(int x) : data(x), left(NULL), right(NULL) {}
};

struct node* insert(struct node *root, int value){
    if(root == NULL){ //a arvore ta vazia ou eu consegui chegar ao node leaf pra fazer a insercao
        return new node(value);
    }
    if(value < root->data){
        root->left = insert(root->left, value);
    }else if(root->data < value){
        root->right = insert(root->right, value);
    }
    return root;
}

struct node* search(struct node *root, int target){
    if(root == NULL || root->data == target){ //se eu cheguei ao final da BST(nao achei o node) ou se eu achei o node. Eu simplesmente o retorno.
        return root;
    }
    //caso contrario, eu continuo a minha busca de forma recursiva, descendo na BST.
    if(target < root->data){ //continuo a busca na sub-arvore da esquerda.
        return search(root->left, target);
    }
    //caso contrario, continuo a minha busca na sub-arvore da direita.
    return search(root->right, target);
}

void inorder_traversal(struct node *root){
    if(root == NULL) return;
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
    return;
}

/***********************************************************************************************/
//Funcao que dado um node, busca o seu inorder sucessor. Exerce o papel de funcao auxiliar.
struct node* minValueNode(struct node *temp){
    struct node *current = temp;
    while(current != NULL && current->left != NULL){
        current = current->left;
    }
    return current;
}

//Funcao que realiza a exclusao/delecao de um node da minha BST.
struct node* deleteNode(struct node *root, int target){
    if(root == NULL) return root;
    
    //If the key to be deleted is smaller than the root's key, then it lies in the left subtree.
    if(target < root->data){
        root->left = deleteNode(root->left, target);
    }
    //If the key to be deleted is greater than the root's key, then it lies in the right subtree.
    else if(root->data < target){
        root->right = deleteNode(root->right, target);
    }
    //If root->data == target, then this is the node to be deleted.
    else{ // root->data == target
        //Node with only one child or no child at all.
        if(root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        //Node that has two(2) children.
        struct node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
        
    }
    return root;
}
/***********************************************************************************************/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    struct node *root = NULL;
    struct node *retrieval;
    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 1);
    
    inorder_traversal(root);
    cout << "\n";
    root = deleteNode(root, 3);
    inorder_traversal(root);
    
    
    return 0;
}

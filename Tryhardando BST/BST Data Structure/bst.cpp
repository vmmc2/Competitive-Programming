#include <bits/stdc++.h>
#include <sstream>
#include <cmath>

using namespace std;

//ESTOU CONSIDERANDO QUE A BINARY SEARCH TREE (BST) NAO PODE CONTER DUPLICATAS!!!!

struct node{
    int data;
    struct node *left;
    struct node *right;
    node(int x) : data(x), left(NULL), right(NULL) {}
};

struct node* insertion(struct node *root, int val){
    if(root == NULL){ //arvore vazia.
        return new node(val);
    }
    if(root->data > val){
        root->left = insertion(root->left, val);
    }else if(root->data < val){
        root->right = insertion(root->right, val);
    }
    return root;
}

struct node* search(struct node *root, int target){
    if(root == NULL || root->data == target){ //nesse caso, ou o node nao ta presente na BST ou achamos ele de boa.
        return root;
    }
    if(root->data < target){ //tem que procurar na sub-arvore da direita.
        return search(root->right, target);
    }
    return search(root->left, target); //tem que procurar na sub-arvore da esquerda.
}

void inorder_traversal(struct node *root){
    if(root == NULL) return;
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    struct node *root = NULL;
    root = insertion(root, 50);
    root = insertion(root, 10);
    root = insertion(root, 20);
    root = insertion(root, 30);
    
    inorder_traversal(root);
    
    
    return 0;
}

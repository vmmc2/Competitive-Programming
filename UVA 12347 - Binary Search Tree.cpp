#include <iostream>
#include <cstdio>

using namespace std;

//estrutura representando cada node da arvore
struct node{
    int data; //elemento que sera guardado
    struct node *left; //Ponteiro para o vertice da esquerda
    struct node *right;//Ponteiro para o vertice da direita
};
//funcao para criar o meu node da arvore
struct node *newnode(int x){
    //criando o node propriamente
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    //acessando os campos do node e atribuindo os valores
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
//funcao para inserir um novo elemento na minha BST
struct node *insert(struct node *raiz, int x){
    //Condicional para caso a minha arvore esteja vazia: raiz == NULL
    if(raiz == NULL){
        return newnode(x);
    }
    //Caso a minha arvore nao esteja vazia eu devo percorre-la
    //e atraves das condicionais, inserir o elemento na posicao correta
    if(x < raiz->data){
        raiz->left = insert(raiz->left, x);
    }
    else if(x > raiz->data){
        raiz->right = insert(raiz->right, x);
    }
    return raiz;
}
//Funcao especifica para printar a arvore em PostOrder
void printPostOrder(struct node *root){
    if(root == NULL){
        return;
    }
    //Primeiro a gente tem que printar sub-arvore da esquerda
    printPostOrder(root->left);
    //Agora a sub-arvore da direita
    printPostOrder(root->right);
    printf("%d\n", root->data);

}
int main(){
    int key;
    struct node *root = NULL;
    while(scanf("%d", &key) != EOF){
        root = insert(root,key);
    }
    printPostOrder(root);
    return 0;
}

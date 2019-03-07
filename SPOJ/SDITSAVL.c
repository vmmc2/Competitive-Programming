#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <string.h>
//Variavel global que vai me indicar se um node existe ou nao na arvore AVL e Struct que vai indicar como funciona o meu node
int flag = 0; 
struct AVLNode{ 
    int data; 
    struct AVLNode* filhoesquerdo;
    struct AVLNode* filhodireito; 
    int height;//Essa variavel eh responsavel por guardar a altura da maior sub-arvore que esta associada a esse node 
    int desc; //Variavel responsavel por armazenar a quantidade de descendentes que um certo node possui
};
/* X-----------X PROTOTIPOS DAS FUNCOES USADAS X-------------X */
int maximo(int a, int b);   
int height(struct AVLNode *temporario);  
struct AVLNode* newNode(int x);
struct AVLNode* RotacaoDireita(struct AVLNode* temp);
struct AVLNode* RotacaoEsquerda(struct AVLNode *temp);
int Balanceamento(struct AVLNode *temp);
struct AVLNode* insert(struct AVLNode* node, int data);
int ConteNodeMaior(struct AVLNode* root, int x);
/* ----------- FUNCAO MAIN ------------ */
int main(){ 
    int i;
    struct AVLNode* root = NULL;
    int casos;
    int operations, valor, volta;
    int qtdnodes = 0, maiores, resposta;
    scanf("%d", &casos);
    for(i = 1; i <= casos; i++){
        scanf("%d %d", &operations, &valor);
        if(operations == 1){
            root = insert(root, valor);
            qtdnodes++;
        }
        else if(operations == 2){
            maiores = ConteNodeMaior(root, valor);
            if(flag == 0){
                printf("Data tidak ada\n");
            }
            else{
                //A resposta eh a quantidade de nodes que existem na minha arvore menos a quantidade de nodes que sao maiores do que o node que foi fornecido no caso
                resposta = qtdnodes - maiores;
                printf("%d\n", resposta);
                flag = 0;
            }
        }
    }
    return 0; 
}
//Funcao para calcular o maximo de dois numeros fornecidos
int maximo(int a, int b) { 
    if(a >= b){
        return a;
    } 
    else if(a < b){
        return b;
    }
}
//Funcao que vai me retornar a altura de uma subarvore baseada no node que foi fornecido
int height(struct AVLNode *temporario) { 
    if (temporario == NULL) 
        return 0; 
    return temporario->height; 
}
struct AVLNode* newNode(int x){ 
    struct AVLNode* temp = (struct AVLNode*)malloc(sizeof(struct AVLNode)); 
    temp->data = x; //Inserindo o valor que vai ser armazenado no meu node
    temp->filhoesquerdo = NULL; 
    temp->filhodireito = NULL; 
    temp->height = 1;//Por questoes de convencao, a gente assume a altura base vale 1
    temp->desc = 0;// Tbm assumimos que o novo node inserido funciona como uma folha. Logo, ele nao possui nenhum descendente
    return temp; 
}
struct AVLNode* RotacaoDireita(struct AVLNode* temp){ 
    struct AVLNode *x; 
    struct AVLNode *temp2; 
    x = temp->filhoesquerdo; 
    temp2 = x->filhodireito; 
    x->filhodireito = temp; 
    temp->filhoesquerdo = temp2; 
    temp->height = maximo(height(temp->filhoesquerdo), height(temp->filhodireito)) + 1; 
    x->height = maximo(height(x->filhoesquerdo), height(x->filhodireito)) + 1;
    int val;  
    if(temp2 != NULL){
        val = temp2->desc;
    }
    else{
        val = -1;
    }     
    temp->desc = temp->desc - (x->desc + 1) + (val + 1); 
    x->desc = x->desc - (val + 1) + (temp->desc + 1); 
    return x; 
}
struct AVLNode* RotacaoEsquerda(struct AVLNode *temp) {
    struct AVLNode *y;
    struct AVLNode *T2; 
    y = temp->filhodireito; 
    T2 = y->filhoesquerdo; 
    y->filhoesquerdo = temp; 
    temp->filhodireito = T2; 
    temp->height = maximo(height(temp->filhoesquerdo), height(temp->filhodireito)) + 1; 
    y->height = maximo(height(y->filhoesquerdo), height(y->filhodireito)) + 1; 
    int auxiliar2;
    if(T2 != NULL){
        auxiliar2 = T2->desc;
    }
    else{
        auxiliar2 = -1;
    } 
    temp->desc = temp->desc - (y->desc + 1) + (auxiliar2 + 1); 
    y->desc = y->desc - (auxiliar2 + 1) + (temp->desc + 1); 
    return y; 
}
//Funcao que vai me retornar o fator de balanceamento de um node da minha arvore AVL
//Lembrando que para que ela seja considerada uma arvore AVL balanceada, todos os seus nodes
//devem ter um fator de balanceamento na seguinte faixa: -1 <= balanceamento <= 1  
int Balanceamento(struct AVLNode *temp) { 
    if (temp == NULL){//Esse eh o caso em que temos uma folha. Ambas as subarvores da esquerda e da direita apresentam
    //a mesma altura. Logo, a subtracao entre esses valores vai dar 0
       return 0;  
    }
    //Caso contrario, eu tenho que efetuar de fato a subtracao entre as alturas dessas subarvores     
    return height(temp->filhoesquerdo) - height(temp->filhodireito); 
}
//Funcao para inserir um novo node na minha AVL. Ja tenho que fazer as rotacoes para manter o 
//balanceamento dos nodes nessa funcao.
struct AVLNode* insert(struct AVLNode* node, int data){ 
    if (node == NULL){//Se a minha raiz for vazia, quer dizer que a minha arvore ta vazia.
    //Isso tambem vale quando eu chego em um node que ta vazio. Logo, tem que criar esse novo node. 
        return newNode(data); 
    }
    //Nesses dois proximos casos eu so vou fazendo a busca binaria na AVL
    //para poder encontrar a posicao correta de insercao do novo node.
    if (data < node->data) { 
        node->filhoesquerdo = insert(node->filhoesquerdo, data); 
        node->desc++;//Aqui eu tenho que sempre ir atualizando a qtd de descendentes. Porque eu meio que estou passando por todos esses nodes para inserir um novo node abaixo deles 
    } 
    else if (data > node->data) { 
        node->filhodireito = insert(node->filhodireito, data); 
        node->desc++;//Aqui eu tenho que sempre ir atualizando a qtd de descendentes. Porque eu meio que estou passando por todos esses nodes para inserir um novo node abaixo deles 
    } 
    //Atualizando as alturas de ambas as sub-arvores(esquerda e direita)
    node->height = 1 + maximo(height(node->filhoesquerdo), height(node->filhodireito)); 
    //Depois de atualizar, tenho que checar o fator de balanceamento, pra ver se algum node ficou desbalanceado.
    int balance = Balanceamento(node); 
    //Se tiver ficado, vou ter que fazer as rotacoes: L, R, LR, RL
    //1. Primeiro caso: Rotacao simples a direita.
    if (balance < -1 && data > node->filhodireito->data) 
        return RotacaoEsquerda(node);  
    //2. Segundo caso: Rotacao simples a esquerda
    if (balance > 1 && data < node->filhoesquerdo->data) 
        return RotacaoDireita(node); 
    //3. Terceiro caso: Rotacao dupla: Esquerda-Direita
    if (balance > 1 && data > node->filhoesquerdo->data) { 
        node->filhoesquerdo = RotacaoEsquerda(node->filhoesquerdo); 
        return RotacaoDireita(node); 
    } 
    //4. O ultimo caso: Rotacao dupla: Direita-Esquerda
    if (balance < -1 && data < node->filhodireito->data) { 
        node->filhodireito = RotacaoDireita(node->filhodireito); 
        return RotacaoEsquerda(node); 
    } 
    return node; 
}
//O pulo do gato: Funcao que vai retornar quantos nodes sao maiores do que 
//o node que eu passei como parametro (se o node existir na minha AVL). No caso, o parametro eh o inteiro x
int ConteNodeMaior(struct AVLNode* root, int x) { 
    int auxiliar = 0; 
    while (root != NULL){ 
        if(root->data == x){
            flag++;
        }
        int desc;
        if(root->filhodireito != NULL){
            desc = root->filhodireito->desc;
        }
        else{
            desc = -1;
        }  
        if(root->data > x){ 
            auxiliar = auxiliar + desc + 1 + 1; 
            root = root->filhoesquerdo; 
        }
        else if(root->data < x){ 
            root = root->filhodireito;
        }     
        else{ 
            auxiliar = auxiliar + desc + 1; 
            break; 
        } 
    } 
    return auxiliar; 
}    

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//Cada elemento da minha fila vai ser um node
struct node{
    int data;
    struct node *next;
};
struct queue{
    struct node *head, *tail;
};
struct queue *create_queue(){ //A funcao vai criar a lista e fazer com que tanto head como tail apontem para NULL
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}
void Enqueue(struct queue *q, int x){//Funcao para adicionar um elemento no final da minha fila
    //Criando o node/elemento da minha fila
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    //Alterando os ponteiros
    if(q->head == NULL && q->tail == NULL){//Se a minha lista está vazia
        q->head = q->tail = temp;
        return;
    }
    //Caso a minha lista nao esteja vazia
    q->tail->next = temp;
    q->tail = temp;
}
void Dequeue(struct queue *q){//Funcao para retirar um elemento do inicio da minha fila
    if(q->head == NULL){//Isso quer dizer que a minha fila ja está vazia
        return;
    }
    q->head = q->head->next;
    if(q->head == NULL){//Se a minha lista ficar vazia. (Ou seja, se eu retirar o ultimo elemento, eu tenho que fazer com que head e tail apontem para NULL)
        q->tail = NULL;
    }

}
void Print(struct queue *q){
    while(q->head != NULL){
        printf("%d\n", q->head->data);
        q->head = q->head->next;
    }
}
//A ideia na questao vai ser fazer duas filas: uma para a margem esquerda e outra para a margem direita
//fila da esquerda: comeca vazia
//struct node *headleft = NULL;
//struct node *tailleft = NULL;
//fila da direita: comeca vazia
//struct node *headright = NULL;
//struct node *tailright = NULL;
int main(){
    struct queue *left;//fila da esquerda
    struct queue *right;//fila da direita
    int numcasos, capacidade;//Capacidade é o comprimento da barca
    int tamanhoferry, qtdcarros, i, tamanhocarro, j;
    char localizacao[10]; //vai me dizer em qual margem o carro se encontra
    int aux, can = 1; //vai servir para sinalizar se eu estou indo da esquerda para a direita ou da direita para a esquerda
    scanf("%d\n", &numcasos);
    for(i = 1; i <= numcasos; i++){
        //A cada caso de teste eu tenho que criar duas filas: uma para a margem esquerda e outra para a margem direita
        left = create_queue();
        right = create_queue();
        scanf("%d %d", &tamanhoferry, &qtdcarros);
        tamanhoferry = tamanhoferry*100; //convertendo de metros para centimetros
        for(j = 1; j <= qtdcarros; j++){
            scanf("%d %s", &tamanhocarro, localizacao);//o tamanho do carro ja está em centimetros
            if(strcmp(localizacao,"left") == 0){
                Enqueue(left, tamanhocarro);//Preenchendo a fila da esquerda
            }
            else if(strcmp(localizacao,"right") == 0){
                Enqueue(right, tamanhocarro);//Preenchendo a fila da direita
            }
        }
    
        j = 0;
        //A partir desse ponto todas as filas (tanto da esquerda como da direita) ja estarão prontas.
        while(can){ //O ferry parte da esquerda. Entao vou adotar a seguinte convencao: Quando j for impar, eu to saindo da margem da esquerda. Quando j for par eu to saindo da margem da direita
            if(left->head == NULL && right->head == NULL){
                break;
            }
            capacidade = tamanhoferry;
            if(j%2 == 0){//Se J for par: To saindo da margem esquerda em direcao a  margem direita
                while(left->head != NULL && capacidade - (left->head->data) >= 0){
                    capacidade = capacidade - (left->head->data);
                    Dequeue(left); 
                }
            }
            if(j%2 != 0){//Se J for par: To saindo da margem direita em direcao a  margem esquerda
                while(right->head != NULL && capacidade - (right->head->data) >= 0){
                    capacidade = capacidade - (right->head->data);
                    Dequeue(right); 
                }
            }
            j++;
        }
        printf("%d\n", j);
        free(left);
        free(right);
    }
    return 0;
}

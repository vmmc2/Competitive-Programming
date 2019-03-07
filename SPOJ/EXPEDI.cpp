#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 10050
struct parade{
    int fuel;
    int distance;
};
struct parade gastation[MAX];
int heap[MAX];
int atual;
//O bom e velho Selection Sort para ordenar os postos de gasolina
void SelectionSort(struct parade A[], int tam){
    int i, j, maior, troca1, troca2;
    for(i = 0; i <= tam-2; i++){
        maior = i;
        for(j = i+1; j <= tam-1; j++){
            if(A[maior].distance < A[j].distance){
                maior = j;
            }
        }
        if(i != maior){
            troca1 = A[i].distance;
            A[i].distance = A[maior].distance;
            A[maior].distance = troca1;

            troca2 = A[i].fuel;
            A[i].fuel = A[maior].fuel;
            A[maior].fuel = troca2;
        }
    }
}
//Funcao para inserir um elemento na minha heap
//aproveitando e ja dando o heapify na heap
//Insercao Top-Down (sob demanda)
void InsereHeap(int x){
    int i;
    atual = atual + 1;
    i = atual;
    while(i != 1){
        if(heap[(i/2)] < x){
            heap[i] = heap[(i/2)];
        }
        else{
            break;
        }
        i = i/2;
    }
    heap[i] = x;
}
//Funcao para retirar a raiz da minha heap
//Nessa questao eu to retirando a maior quantidade de
//combustivel que eu ja adquiri durante o percurso
int RemoveRaiz(){
    int maximo, valor, folha, i;
    if(atual == 0){//Se a minha heap ta vazia, quer dizer que deu ruim e eu nao vou conseguir completar o percurso
        return -1;
    }
    valor = heap[atual--];
    maximo = heap[1]; //pegando a raiz da minha maxheap
    i = 1;
    while(i*2 <= atual){
        folha = i*2;
        if(folha + 1 <= atual && heap[folha+1] > heap[folha]){
            folha++;//Checando qual dos dois filhos do node eh maior.
            //E deslocando o "cursor" para ele
        }
        if(heap[folha] > valor){
            heap[i] = heap[folha];
        }
        else{//Deu merda
            break;
        }
        i = folha;
    }
    heap[i] = valor;
    return maximo;
}
void vaquinhas(){
    int numpostos, i, k, temporario;
    int truckfuel, dtruckcity;
    scanf("%d", &numpostos);
    for(i = numpostos - 1; i >= 0; i--){
        scanf("%d %d", &gastation[i].distance, &gastation[i].fuel);
    }
    gastation[numpostos].distance = 0;
    gastation[numpostos].fuel = 0;
    SelectionSort(gastation, numpostos+1);
    scanf("%d %d", &dtruckcity, &truckfuel);
    i = 0;
    atual = 0;
    k = 0;
    while(i <= numpostos){
        while(i <=numpostos && (abs(dtruckcity - gastation[i].distance) <= truckfuel)){
            truckfuel = truckfuel - (dtruckcity - gastation[i].distance);
            dtruckcity = gastation[i].distance;
            InsereHeap(gastation[i].fuel);
            i = i+1;
        }
        if(i <= numpostos){
            temporario = RemoveRaiz();
            if(temporario == -1){//Fudeu, a Heap ta vazia e as vacas se lascaram rsrs
                k = -1;
                break;
            }
            truckfuel = truckfuel + temporario;
            k++;
        }
    }
    printf("%d\n", k);
}
int main(){
    int i;
    int numcasos;
    scanf("%d", &numcasos);
    for(i = 1; i <= numcasos; i++){
        vaquinhas();
    }
    return 0;
}

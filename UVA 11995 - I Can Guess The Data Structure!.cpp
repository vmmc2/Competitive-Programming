#include <bits/stdc++.h>

using namespace std;

int main(){
    int elemento, operacao, numcasos, i;
    int isStack = 1, isQueue = 1, isHeap = 1;

    while(scanf("%d", &numcasos) != EOF){
        stack <int> pilha;
        queue <int> fila;
        priority_queue <int> heap;
        //A cada caso de teste eu assumo que 
        //eu tenho uma pilha, uma fila e uma heap
        isStack = 1,
        isQueue = 1, 
        isHeap = 1;
        for(i = 1; i <= numcasos; i++){
            scanf("%d %d", &operacao, &elemento);
            if(operacao == 1){//Tenho que inserir
            //um elemento na minha DS
            pilha.push(elemento);
            fila.push(elemento);
            heap.push(elemento);
            }
            else if(operacao == 2){//Tenho que retira
            //r um elemento da minha DS
                if(pilha.empty() || pilha.top() != elemento){
                    isStack = 0;
                }
                else if(pilha.top() == elemento){
                    pilha.pop();
                }
                if(fila.empty() || fila.front() != elemento){
                    isQueue = 0;
                }
                else if(fila.front() == elemento){
                    fila.pop();
                }
                if(heap.empty() || heap.top() != elemento){
                    isHeap = 0;
                }
                else if(heap.top() == elemento){
                    heap.pop();
                }
            }
        }
        if(isStack == 1 && isHeap == 0 && isQueue == 0){
            cout << "stack" << endl;
        }
        else if(isQueue == 1 && isStack == 0 && isHeap == 0){
            cout << "queue" << endl;
        }
        else if(isHeap == 1 && isQueue == 0 && isStack == 0){
            cout << "priority queue" << endl;
        }
        else if(isStack == 0 && isHeap == 0 && isQueue == 0){
            cout << "impossible" << endl;
        }
        else{
            cout << "not sure" << endl;
        }
    }
    return 0;
}

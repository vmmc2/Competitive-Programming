#include <bits/stdc++.h>
#include <sstream>
#include <cmath>

using namespace std;

struct node{
  int val;
  int minimo;
  struct node *next;
  node(int x) : val(x), minimo(x), next(NULL) {}
};

struct node *head = NULL; //Ponteiro para o inicio da minha stack.
int length = 0; //Tamanho da minha pilha. Ou seja, quantidade de nodes presentes dentro dela.

void push(int valor){ //inserir elemento na minha stack
    struct node *temp = new node(valor);
    if(head == NULL || length == 0){ //se a stack ta inicialmente vazia, basta colocar esse novo elemento.
        head = temp;
        length++;
    }else{
        temp->next = head;
        temp->minimo = min(temp->minimo, head->minimo);
        head = temp;
        length++;
    }
    return;
}

void pop(){ //retirar elemento da minha stack
    if(head == NULL || length == 0) throw "Stack is empty!!\n";
    head = head->next;
    length--;
    return;
}

int top(){ //retornar elemento que ta no topo da minha stack
    if(head == NULL || length == 0) throw "Stack is empty!\n";
    return head->val;
}

int size(){ //retornar a quantidade de elementos presentes na minha stack. Ou seja, devo retornar size.
    return length;
}

bool isEmpty(){ //checar se a stack ta vazia ou nao.
    if(head == NULL || length == 0) return true;
    else return false;
}

void clear(){ //limpar a stack.
    head = NULL;
    length = 0;
    return;
}

int min(){ //retornar o elemento minimo que tem na minha stack naquele momento.
    if(head == NULL || length == 0) throw "Stack is empty!\n";
    return head->minimo;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int minimal;
    int topo;
    int tam;
    
    push(3);
    push(2);
    push(1);
    tam = size();
    cout << tam << "\n";
    pop();
    pop();
    tam = size();
    topo = top();
    cout << topo << "\n";
    
    
    
    return 0;
}

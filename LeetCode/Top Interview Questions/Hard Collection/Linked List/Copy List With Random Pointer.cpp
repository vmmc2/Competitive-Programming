/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <unordered_map>

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Treating the conner cases: If the linked list is empty.
        if(head == NULL) return head;
        //A partir daqui a gente trata os casos mais gerais.
        //Para resolver esse problema a gente vai ter que usar um Map de tal forma que a gente
        //consiga mapear os nodes originais da lista original para os nodes clonados.
        //A partir dai oq resta eh apenas iteracao linear.
        unordered_map<Node*, Node*> mapa; // To usando unordered_map para deixar mais eficiente -> O(1).
        
        //Na primeira passada pela lista, a gente simplesmente vai criar o mapa
        Node *temp = head;
        while(temp != NULL){
            mapa[temp] = new Node(temp->val); //um endereco mapeando para outro endereco.
            temp = temp->next;
        }
        
        //Segunda passada: A gente reseta o ponteiro temp para a head da lista original.
        //Ou seja: temp = head;
        //E a medida q vamos iterando, a gente vai atribuindo o random e o next pointer.
        temp = head;
        while(temp != NULL){
            mapa[temp]->next = mapa[temp->next];
            mapa[temp]->random = mapa[temp->random];
            temp = temp->next;
        }
        return mapa[head];
    }
};

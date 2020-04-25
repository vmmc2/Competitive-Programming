# Linked List

## Linked List Cycle
* Na questao linked list cycle, na hora de fazer o while loop para checar se o ponteiro fast ou se o ponteiro depois do next chegaram ao fim da linked list, faca o seguinte (sem alterar a ordem das condicoes):
```c++
while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast) return true;
}
```

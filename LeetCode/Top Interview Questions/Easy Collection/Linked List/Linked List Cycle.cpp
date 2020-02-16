/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Faz um map que guarda o endereco de cada node. Pode ser um set tbm. Se tiver um ciclo, a gente vai visitar
//o mesmo node(mesmo endereco) mais de uma vez.
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode *> javistos;
        ListNode *davez;
        ListNode *cursor = head;
        while(cursor != NULL){
            davez = cursor;
            if(javistos.find(davez) != javistos.end()){
                return true;
            }
            javistos.insert(davez);
            cursor = cursor->next;
        }
        return false;
    }
};

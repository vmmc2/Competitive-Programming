/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sit;
        ListNode *sentinel = head; //esse vai se movimentando na frente
        ListNode *delayed = head; //esse vai atras e vai ser o responsavel por fazer o delete.
        for(int i = 1; i <= n; i++){
            sentinel = sentinel->next;
        }
        //Conner case em que temos 1 elemento na lista
        if(head->next == NULL){
            head = NULL;
            return head;
        }
        //Conner case em que queremos deletar o primeiro elemento da lista.
        if(sentinel == NULL){
            cout << "entrei" << "\n";
            delayed = delayed->next;
            head = delayed;
            return head;
        }
        while(sentinel->next != NULL){
            sentinel = sentinel->next;
            delayed = delayed->next;
        }
        delayed->next = delayed->next->next;
        return head;
    }
};

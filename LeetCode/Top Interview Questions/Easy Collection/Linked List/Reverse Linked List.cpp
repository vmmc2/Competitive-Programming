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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){ //conner case: lista vazia.
            cout << "opa" << "\n";
            return head;
        }
        if(head->next == NULL){ //conner case: lista com 1 unico elemento.
            cout << "dale" << "\n";
            return head;
        }
        ListNode *prev = NULL;
        ListNode *prox = head->next;
        ListNode *curr = head;
        while(true){
            curr->next = prev;
            prev = curr;
            if(prox == NULL){
                break;
            }
            curr = prox;
            prox = prox->next;
        }
        return curr;
    }
};

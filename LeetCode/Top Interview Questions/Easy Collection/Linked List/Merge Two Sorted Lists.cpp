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
    ListNode *head = NULL;
    ListNode *Sentinel = NULL;
    void InsertNode(int value){
        ListNode *temp = new ListNode(value);
        if(head == NULL){
            head = temp;
        }
        if(Sentinel == NULL){
            Sentinel = temp;
        }else if(Sentinel != NULL){
            Sentinel->next = temp;
            Sentinel = Sentinel->next;
        } 
        return;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        while(true){
            if(l1 == NULL && l2 == NULL){
                break; //acabei de percorrer as duas lists.
            }
            else if(l1 == NULL && l2 != NULL){ //percorro l2 todinha ate o fim e saio jogando os numeros.
                while(l2 != NULL){
                    InsertNode(l2->val);
                    l2 = l2->next;
                }
            }
            else if(l1 != NULL && l2 == NULL){ //percorro l1 todinha ate o fim e saio jogando os numeros
                while(l1 != NULL){
                    InsertNode(l1->val);
                    l1 = l1->next;
                }
            }
            else if(l1 != NULL && l2 != NULL){ //tenho que checar quem tem o menor e jogar pra list e avancar com os ponteiros. se for o caso.
                if(l1->val <= l2->val){ //jogo o valor de l1 na lista e movo o ponteiro de l1
                    InsertNode(l1->val);
                    l1 = l1->next;
                }else{
                    InsertNode(l2->val);
                    l2 = l2->next;
                }
            }
        }
        return head;
    }
};

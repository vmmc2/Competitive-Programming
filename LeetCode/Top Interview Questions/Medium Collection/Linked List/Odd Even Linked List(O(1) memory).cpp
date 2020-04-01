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
    ListNode* oddEvenList(ListNode* head) {
        //Conner case in which the list has 0 nodes (empty list) or the list has only 1 node.
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenhead = even;
        while(even != NULL && even->next != NULL){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }
};

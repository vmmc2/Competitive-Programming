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
        //Question to be asked to our interviewer: Does the number "n" is always a valid number?
        //After that, we have to deal with the conner cases: Which are 2: An empty linked list and a linked list
        //with only one element. We are assuming that "n" is ALWAYS a valid number in this question.
        if(head == NULL || head->next == NULL) return NULL;
        ListNode *delayed = head;
        ListNode *forward = head;
        for(int i = 1; i <= n; i++){
            forward = forward->next;
        }
        if(forward == NULL){//In this case, we must delete the first element of our linked list.
            head = head->next;
            return head;
        }
        //Otherwise, we must delete another node.
        while(forward->next != NULL){
            forward = forward->next;
            delayed = delayed->next;
        }
        delayed->next = delayed->next->next;
        return head;
    }
};

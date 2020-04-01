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
        //First of all we have to treat the conner cases
        if(head == NULL || head->next == NULL) return NULL;
        //now we treat all the other cases (general ones)
        ListNode *temp1 = head;
        ListNode *temp2 = head;
        int qtdnodes = 0;
        int target;
        int k = 0;
        //Discovering how many nodes are in the linked list.
        while(temp2->next != NULL){
            qtdnodes++;
            temp2 = temp2->next;
        }
        qtdnodes++;
        target = qtdnodes - n;
        if(target == 0){ //in this particular case, we have to delete the first node
        //of our linked list
            head = temp1->next;
            return head;
        }
        while(k != target - 1){
            k++;
            temp1 = temp1->next;
        }
        temp1->next = temp1->next->next;
        
        return head;
    }
};

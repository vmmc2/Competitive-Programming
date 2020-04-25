/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Para fazer a ordenacao de tempo O(n*log(n)) e com memoria O(1), temos que usar o MergeSort!!

class Solution {
public:
    ListNode* merge(ListNode *l1, ListNode *l2){
        ListNode *sorted_temp = new ListNode(0);
        ListNode *current_node = sorted_temp;
        
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                current_node->next = new ListNode(l1->val);
                l1 = l1->next;
            }else{
                current_node->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            current_node = current_node->next;
        }
        
        if(l1 != NULL){
            current_node->next = l1;
            l1 = l1->next;
        }
        if(l2 != NULL){
            current_node->next = l2;
            l2 = l2->next;
        }
        
        return sorted_temp->next;
    }
    ListNode* sortList(ListNode* head) {
        //first thing to do is to treat the corner cases: an empty list and a list with only one node
        //if that's the case, then the list is already sorted.
        if(head == NULL || head->next == NULL) return head;
        
        //Now we treat the general cases...
        ListNode *temp = head;
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast != NULL && fast->next != NULL){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        //At the end of this part above here is what we are going to have:
        //1) head is going to point to the beginning of the first half and temp is going to point to the end
        //of the first half.
        //2) slow is going to point to the beginning of the second half and fast is going to point to the end
        //of the second half.
        
        ListNode *left_side = sortList(head);
        ListNode *right_side = sortList(slow);
        
        return merge(left_side, right_side);
    }
};

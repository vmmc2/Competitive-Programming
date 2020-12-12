/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //corner case
        if(head == NULL || head->next == NULL) return head;
        
        //general cases
        ListNode* curr1 = head;
        ListNode* curr2 = head->next;
        bool dupliFirst = true;
        while(curr2 != NULL){
            if(curr1->val == curr2->val){
                curr2 = curr2->next;
                if(curr2 == NULL) curr1->next = curr2;
            }else{
                curr1->next = curr2;
                curr1 = curr2;
                curr2 = curr2->next;
            }
        }
        
        return head;
    }
};

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
    ListNode* removeElements(ListNode* head, int val) {
        //corner case
        if(head == NULL) return head;
        // general cases
        while(head != NULL && head->val == val){
            head = head->next;
        }
        ListNode* temp = head;
        ListNode* temp2 = head;
        while(temp2 != NULL){
            if(temp2->val == val){
                temp2 = temp2->next;
                temp->next = temp2;
            }else{
                temp = temp2;
                temp2 = temp2->next;
            }
            
        }
        return head;
    }
};

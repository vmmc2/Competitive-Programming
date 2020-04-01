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
    void deleteNode(ListNode* node) {
        ListNode *ace = node;
        while(true){
            ace->val = ace->next->val;
            if(ace->next->next == NULL){
                ace->next = NULL;
                break;
            }else{
                ace = ace->next;
            }
        }
        return;
    }
};

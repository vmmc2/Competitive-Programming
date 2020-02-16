/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *head2;


void setar(ListNode *head){
    head2 = head;
    return;
}

class Solution {
public:
    bool check(ListNode *cursor){
        bool pseudo = true;
        if(cursor->next == NULL){ //chegamos no fim
            if(cursor->val != head2->val){
                pseudo = false;
                return pseudo;
            }else{
                return pseudo;
            }
        }
        pseudo = check(cursor->next);
        head2 = head2->next;
        if(head2 != NULL){
            if(cursor->val != head2->val){
                pseudo = false;
                return pseudo;
            }else{
                return pseudo;
            }
        }
        return pseudo;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        bool palindrome;
        bool pseudo = true;
        setar(head);
        ListNode *cursor = head;
        palindrome = check(cursor);
        return palindrome;
    }
};

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
    ListNode* reverse_list(ListNode *head){
        ListNode *prev = NULL;
        while(head != NULL){
            ListNode *temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        //first of all, we must treat the conner cases: the cases in which we have an empty list and a list
        //with only one node. In both cases, they are palindromes by definition.
        if(head == NULL) return true;
        if(head->next == NULL) return true;
        //treating the general cases...
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = reverse_list(slow);
        fast = head;
        while(slow != NULL){
            if(slow->val != fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};

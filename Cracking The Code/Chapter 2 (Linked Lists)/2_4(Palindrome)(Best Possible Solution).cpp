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
    ListNode* reverse_linked_list(ListNode *head){
        ListNode *prev = NULL;
        while(head != NULL){
            ListNode *temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    void print_list(ListNode* head){
        while(head != NULL){
            cout << head->val << " -> ";
            head = head->next;
        }
        cout << "NULL" << "\n";
        return;
    }
    
    bool isPalindrome(ListNode* head) {
        //The "slow" pointer is going to move one node per iteration while the "fast" node will move two nodes
        //per iteration.
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        //After that, we reset the fast pointer
        fast = head;
        slow = reverse_linked_list(slow); //Here we created a new list and assigned it to slow.
        print_list(slow);
        //And we just do a checking, comparing the correspondent nodes.
        while(slow != NULL){
            cout << fast->val << " " << slow->val << "\n";
            if(fast->val != slow->val) return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};

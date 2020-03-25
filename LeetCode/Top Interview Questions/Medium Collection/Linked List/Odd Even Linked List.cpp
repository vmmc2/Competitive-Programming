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
        ListNode *cursor = head;
        ListNode *headEven = NULL;
        ListNode *cursorEven = NULL;
        ListNode *headOdd = NULL;
        ListNode *cursorOdd = NULL;
        if(head == NULL) return headOdd;
        for(int i = 1; i > 0; i++){
            if(cursor == NULL) break; //reached the end of the list.
            if(i == 1){
                cursorOdd = new ListNode(cursor->val);
                headOdd = cursorOdd;
            }else if(i == 2){
                cursorEven = new ListNode(cursor->val);
                headEven = cursorEven;
            }
            if(i % 2 == 1 && i != 1){
                cursorOdd->next = new ListNode(cursor->val);
                cursorOdd = cursorOdd->next;
            }
            if(i % 2 == 0 && i != 2){
                cursorEven->next = new ListNode(cursor->val);
                cursorEven = cursorEven->next;
            }
            cursor = cursor->next;
        }
        cursorOdd->next = headEven;
        return headOdd;
    }
};

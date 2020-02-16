/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*

Now consider a cyclic list and imagine the slow and fast pointers are two runners racing around a circle track. The fast runner will eventually meet the slow runner. Why? Consider this case (we name it case A) - The fast runner is just one step behind the slow runner. In the next iteration, they both increment one and two steps respectively and meet each other.

How about other cases? For example, we have not considered cases where the fast runner is two or three steps behind the slow runner yet. This is simple, because in the next or next's next iteration, this case will be reduced to case A mentioned above.

*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
       if(head == NULL || head->next == NULL) return false;
        ListNode *fastercursor = head->next;
        ListNode *slowercursor = head;
        while(fastercursor != slowercursor){
            if(fastercursor == NULL || fastercursor->next == NULL){
                return false;
            }
            slowercursor = slowercursor->next;
            fastercursor = fastercursor->next->next;
        }
        return true;
    }
};

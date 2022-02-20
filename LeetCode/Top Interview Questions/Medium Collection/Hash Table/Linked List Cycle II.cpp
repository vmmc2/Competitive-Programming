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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        ListNode *current = head;
        ListNode *answer = NULL;
        
        while(current != NULL){
            if(visited.find(current) == visited.end()){
                visited.insert(current);
            }else{
                answer = current;
                break;
            }
            current = current->next;
        }
        
        return answer;
    }
};

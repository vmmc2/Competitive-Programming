/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <set>

/*
 COMPLEXIDADE
 
 1) TEMPORAL: O(n*logn) 
 2) ESPACIAL: O(n)
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *cursorA = headA;
        ListNode *cursorB = headB;
        set<ListNode*> cA;
        set<ListNode*> cB;
        //Percorrendo a lista A
        while(cursorA != NULL){
            cA.insert(cursorA);
            cursorA = cursorA->next;
        }
        //Percorrendo a lista B
        while(cursorB != NULL){
            cB.insert(cursorB);
            cursorB = cursorB->next;
        }
        //Checando pra ver se acho o Node em comum...
        for(set<ListNode*>:: iterator it = cA.begin(); it != cA.end(); ++it){
            if(cB.find(*it) != cB.end()){
                return *it;
            }
        }
        return NULL;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <queue>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //Conner case
        if((int)lists.size() == 0) return NULL;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        ListNode *head = NULL;
        ListNode *temp = NULL;
        int n = (int)lists.size();
        //Iterando por todas as listas do meu vetor de listas.
        for(int i = 0; i < n; i++){
            ListNode *temp2 = lists[i];
            //Iterando por todos os nodes de cada lista.
            while(temp2 != NULL){
                minHeap.push(temp2->val);
                temp2 = temp2->next;
            }
        }
        ListNode *dummy = new ListNode(-1); //dummy vai ser o meu node sentinela
        head = dummy;
        while(!minHeap.empty()){
            head->next = new ListNode(minHeap.top());
            minHeap.pop();
            head = head->next;
        }
        return dummy->next;
    }
};

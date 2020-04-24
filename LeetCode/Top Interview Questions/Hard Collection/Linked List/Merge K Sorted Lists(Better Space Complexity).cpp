/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <queue>
#include <utility>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
        //first element -> element from the array/list
        //indexing identifing from which array/list that element came from.
        int n = (int)lists.size();
        ListNode* head = NULL;
        head = new ListNode(-1); //dummy;
        ListNode* cursor = head;
        for(int i = 0; i < n; i++){
            if(lists[i] != NULL){
                min_heap.push({lists[i]->val, i});
                lists[i] = lists[i]->next;
            }
        }
        while(!min_heap.empty()){
            pair<int,int> actual = min_heap.top();
            min_heap.pop();
            cursor->next = new ListNode(actual.first);
            cursor = cursor->next;
            if(lists[actual.second] != NULL){
                min_heap.push({lists[actual.second]->val, actual.second});
                lists[actual.second] = lists[actual.second]->next;
            }
        }
        return head->next;
    }
};

#include <queue>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //A better solution using heap.
        //To be more specific, we are going to use a minHeap
        //RunTime Complexity: O(n*log(k))
        priority_queue<int,vector<int>,greater<int>> minHeap;
        int tam = (int)nums.size();
        for(int i = 0; i < tam; i++){
            minHeap.push(nums[i]);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};

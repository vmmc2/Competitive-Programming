class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> maxHeap;
        for(auto x : stones){
            maxHeap.push(x);
        }
        while(maxHeap.size() > 1){
            int s1 = maxHeap.top();
            maxHeap.pop();
            int s2 = maxHeap.top();
            maxHeap.pop();
            if(s1 != s2){
                maxHeap.push(max(s1,s2) - min(s1,s2));
            }
        }
        if(maxHeap.size() == 1){
            return maxHeap.top();    
        }
        return 0;
    }
};

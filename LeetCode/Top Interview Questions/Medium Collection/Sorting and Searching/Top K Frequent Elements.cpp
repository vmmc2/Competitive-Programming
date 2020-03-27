#include <unordered_map>
#include <queue>
#include <utility>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> answer;
        unordered_map<int,int> hashtable;
        pair<int,int> temp;
        priority_queue<pair<int,int>,vector<pair<int,int>>> heap;
        int tam = (int)nums.size();
        for(int i = 0; i < tam; i++){
            hashtable[nums[i]]++;
        }
        for(unordered_map<int,int>:: iterator it = hashtable.begin(); it != hashtable.end(); ++it){
            heap.push({it->second, it->first});
        }
        for(int i = 1; i <= k; i++){
            temp = heap.top();
            heap.pop();
            answer.push_back(temp.second);
        }
        return answer;
    }
};

#include <unordered_map>
#include <queue>
#include <utility>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> answer;
        unordered_map<int,int> hashtable;
        pair<int,int> temp;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> heap;
        int tam = (int)nums.size();
        for(int i = 0; i < tam; i++){
            hashtable[nums[i]]++;
        }
        for(unordered_map<int,int>:: iterator it = hashtable.begin(); it != hashtable.end(); ++it){
            if(heap.size() < k){ //essa condicao ta correta.
                heap.push({it->second, it->first});
            }else{
                if(it->second > heap.top().first){
                    heap.pop();
                    heap.push({it->second, it->first});
                }
            }
        }
        for(int i = 1; i <= k; i++){
            temp = heap.top();
            heap.pop();
            answer.push_back(temp.second);
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};

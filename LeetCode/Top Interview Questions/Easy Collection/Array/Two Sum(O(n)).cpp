#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashtable; //maps each element in the array to its index in the input array
        int n = (int)nums.size();
        vector<int> answer;
        
        for(int i = 0; i < n; i++){
            int complement = target - nums[i];
            if(hashtable.find(complement) != hashtable.end()){
                answer.push_back(hashtable[complement]);
                answer.push_back(i);
                break;
            }
            hashtable[nums[i]] = i;
        }
        return answer;
    }
};

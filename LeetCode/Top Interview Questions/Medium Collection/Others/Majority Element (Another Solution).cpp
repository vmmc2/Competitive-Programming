//First solution using an unordered_map
#include <unordered_map>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = (int)nums.size();
        unordered_map<int,int> freq;
        int answer;
        
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
            if(freq[nums[i]] > (n/2)){
                answer = nums[i];
                break;
            }
        }
        return answer;
    }
};

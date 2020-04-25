#include <unordered_map>

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> hashtable;
        for(int i = 0; i < (int)nums.size(); i++){
            hashtable[nums[i]]++;
            if(hashtable[nums[i]] > 1) return nums[i];
        }
        return -1;
    }
};

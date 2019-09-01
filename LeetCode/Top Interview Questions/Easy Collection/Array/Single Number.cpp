#include <unordered_map>
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> hashtable;
        int single = 0;
        for(int i = 0; i < (int)nums.size(); i++){
            hashtable[nums[i]]++;
        }
        for(auto it: hashtable){
            if(it.second == 1){
                single = it.first;
            }
        }
        return single;
    }
};

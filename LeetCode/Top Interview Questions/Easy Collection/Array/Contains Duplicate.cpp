#include <map>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<long,int> hashtable;
        bool duplicate = false;
        for(int i = 0; i < (int)nums.size(); i++){
            hashtable[nums[i]]++;
            if(hashtable[nums[i]] >= 2){
                duplicate = true;
            }
        }
        return duplicate;
    }
};

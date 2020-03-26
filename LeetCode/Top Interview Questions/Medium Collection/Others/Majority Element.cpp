#include <unordered_map>
#include <cmath>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int tam = (int)nums.size();
        unordered_map<int,int> hashtable;
        
        for(int i = 0 ; i < tam; i++){
            hashtable[nums[i]]++;
        }
        
        for(unordered_map<int,int>:: iterator it = hashtable.begin(); it != hashtable.end(); ++it){
            if(it->second > tam/2){
                return it->first;
            }
        }
        return 0;
    }
};

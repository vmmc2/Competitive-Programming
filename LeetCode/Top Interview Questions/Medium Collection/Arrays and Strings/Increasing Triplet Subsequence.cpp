#include <cmath>

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if((int)nums.size() < 3) return false;
        int tam = (int)nums.size();
        int minOne = pow(2,31) - 1;
        int minTwo = pow(2,31) - 1;
        for(int i = 0; i < tam; i++){
            if(nums[i] < minOne){
                minOne = nums[i];
            }
            if(nums[i] > minOne){
                minTwo = min(minTwo, nums[i]);
            }
            if(nums[i] > minTwo){
                return true;
            }
        }
        return false;
    }
};

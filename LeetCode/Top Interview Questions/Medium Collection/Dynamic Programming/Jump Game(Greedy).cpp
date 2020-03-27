class Solution {
public:
    bool canJump(vector<int>& nums) {
        if((int)nums.size() == 0) return false;
        if((int)nums.size() == 1) return true;
        int lastGoodIndex = (int)nums.size() - 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(i + nums[i] >= lastGoodIndex){
                lastGoodIndex = i;
            }
        }
        return lastGoodIndex == 0;
    }
};

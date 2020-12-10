class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> dicio;
        bool found = false;
        for(int i = 0; i < (int)nums.size(); i++){
            if(dicio.find(nums[i]) == dicio.end()){
                dicio[nums[i]] = i;
            }else{
                if(abs(dicio[nums[i]] - i) <= k){
                    found = true;
                    break;
                }else{
                    dicio[nums[i]] = i;
                }
            }
        }
        return found;
    }
};

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size(), curr;
        vector<bool> marked(n, false);
        
        for(int i = 1; i <= 3; i++){
            bool isOk = false;
            for(int i = 0; i < n; i++){
                if(marked[i] == false){
                    curr = nums[i];
                    isOk = true;
                    break;
                }    
            }
            if(isOk == false){
                for(int i = 0; i < n; i++){
                    curr = max(curr, nums[i]);
                }
                break;
            }
            for(int i = 0; i < n; i++){
                if(marked[i] == true) continue;
                curr = max(curr, nums[i]);
            }
            for(int i = 0; i < n; i++){
                if(nums[i] == curr) marked[i] = true;
            }
        }
        
        return curr;
    }
};

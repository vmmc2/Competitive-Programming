class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = (int)nums.size();
        if(n == 0) return false;
        bool dp[n];
        int iterations;
        for(int i = 0; i < n; i++){ //supposing that I wont be able to reach each cell.
            dp[i] = false;
        }
        dp[0] = true;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == 0) continue;
            else{
                iterations = nums[i];
                for(int j = 1; j <= iterations; j++){
                    if(i + j >= n) break; //caso em que eu extrapolo o array.
                    dp[i + j] = true;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(dp[i] == false) return false;
        }
        return true;
    }
};

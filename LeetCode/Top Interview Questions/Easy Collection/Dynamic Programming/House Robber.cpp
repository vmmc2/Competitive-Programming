class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        if(n == 0) return 0;
        int dp[n];
        for(int i = 0; i < n; i++){
            if(i == 0){
                dp[i] = nums[0];
            }else if(i == 1){
                dp[i] = max(nums[0], nums[1]);
            }else{
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            }
        }
        return dp[n - 1];
    }
};

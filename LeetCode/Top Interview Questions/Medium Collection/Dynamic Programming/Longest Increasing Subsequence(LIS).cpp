#include <cmath>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;
        int n = (int)nums.size();
        int dp[n];
        int answer = -1;
        for(int i = 0; i < n; i++){
            dp[i] = 1;
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        for(int i = 0; i < n; i++){
            answer = max(answer, dp[i]);
        }
        return answer;
    }
};

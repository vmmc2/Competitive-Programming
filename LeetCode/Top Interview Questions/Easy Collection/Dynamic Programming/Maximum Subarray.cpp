//Using Kadane`s Algorithm --- Time Complexity: O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long ans = -999999999999;
        long long sum = 0;
        for(int i = 0; i < (int)nums.size(); i++){
            sum += nums[i]*1LL;
            ans = max(ans, sum);
            if(sum < 0) sum = 0;
        }
        return ans;
    }
};

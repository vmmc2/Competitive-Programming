class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int answer = -1;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = n/2 - 1, right = n/2;
        
        while(left >= 0 && right < n){
            answer = max(answer, nums[left] + nums[right]);
            left--;
            right++;
        }
        
        return answer;
    }
};

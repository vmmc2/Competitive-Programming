class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer;
        
        for(int i = 0; i < n; i++){
            int curr = abs(nums[i]) - 1;
            nums[curr] = nums[curr] < 0 ? nums[curr] : -nums[curr];
        }
        for(int i = 0; i < n; i++){
            if(nums[i] > 0) answer.push_back(i + 1);
        }
        
        return answer;
    }
};

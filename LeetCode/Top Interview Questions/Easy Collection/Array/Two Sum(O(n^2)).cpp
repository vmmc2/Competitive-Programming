class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        int n = (int)nums.size();
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] + nums[j] == target){
                    answer.push_back(i);
                    answer.push_back(j);
                    break;
                }
            }
        }
        return answer;
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = (int)nums.size() - 1;
        int answer = nums[0];
        while(left <= right){
            int middle = (left + right)/2;
            if(nums[middle] > nums[right]){
                left = middle + 1;
                answer = min(answer, nums[middle]);
            }else{
                right = middle - 1;
                answer = min(answer, nums[middle]);
            }
        }
        
        return answer;
    }
};

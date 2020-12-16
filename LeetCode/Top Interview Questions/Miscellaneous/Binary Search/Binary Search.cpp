class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int low = 0;
        int high = n - 1;
        int answer = -1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                answer = mid;
                return answer;
            }else if(nums[mid] < target){
                low = mid + 1;
            }else if(target < nums[mid]){
                high = mid - 1;
            }
        }
        
        return answer;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return mid;
            if(nums[low] <= nums[mid]){ //primeira metade do segmento ta ordenada.
                //checo se o target pode ta nesse segmento.
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }
            if(nums[mid] <= nums[high]){ //segunda metade do segmento ta ordenada.
                //checo se o target pode ta nesse segmento.
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

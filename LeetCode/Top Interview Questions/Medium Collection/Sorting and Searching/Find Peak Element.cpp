class Solution {
public:
    int binary_search(vector<int> &nums, int left, int right){
        int mid = (left + right)/2;
        if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) return mid;
        if(nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1]){
            return binary_search(nums, mid, right);
        }
        if(nums[mid - 1] > nums[mid] && nums[mid] > nums[mid + 1]){
            return binary_search(nums, left, mid);
        }
        return binary_search(nums, left, mid);
        //EU NAO COLOCO MID - 1 PQ EU POSSO ESTAR IGNORANDO UM PICO.
    }
    
    int findPeakElement(vector<int>& nums) {
        //caso base: Checar se o primeiro ou se o ultimo elemento sao picos.
        if((int)nums.size() == 1) return 0;
        if((int)nums.size() == 2){
            if(nums[0] > nums[1]) return 0;
            if(nums[1] > nums[0]) return 1;
        }
        if(nums[0] > nums[1]) return 0;
        if(nums[(int)nums.size() - 1] > nums[(int)nums.size() - 2]) return (int)nums.size() - 1;
        int tam = (int)nums.size();
        return binary_search(nums, 0, tam - 1);
    }
};

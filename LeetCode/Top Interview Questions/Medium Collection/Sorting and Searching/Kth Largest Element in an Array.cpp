class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int tam = (int)nums.size();
        
        return nums[tam - k];
        
    }
};

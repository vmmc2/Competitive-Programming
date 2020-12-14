class NumArray {
public:
    vector<int> nums1;
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        nums1 = nums;
        prefixSum.resize((int)nums.size());
        if((int)nums1.size() != 0){
            prefixSum[0] = nums1[0];
        
            for(int i = 1; i < (int)nums1.size(); i++){
                prefixSum[i] = prefixSum[i - 1] + nums1[i];
            }    
        }
    }
    
    int sumRange(int i, int j) {
        if(i == j) return nums1[j];
        if(i == 0) return this->prefixSum[j];
        return prefixSum[j] - prefixSum[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

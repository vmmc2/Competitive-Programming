class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int tam = (int)nums.size();
        vector<int> nums1(tam);
        for(int i = 0; i < tam; i++){
            nums1[(i + k)%tam] = nums[i];
        }
        for(int i = 0; i < tam; i++){
            nums[i] = nums1[i];
        }
    }
};

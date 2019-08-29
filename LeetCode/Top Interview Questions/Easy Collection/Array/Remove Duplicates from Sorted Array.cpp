class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int tamanho = 0;
        if(nums.size() == 0) return 0;
        for(int i = 1; i < (int)nums.size(); i++){
            if(nums[tamanho] != nums[i]){
                tamanho++;
                nums[tamanho] = nums[i];
            }
        }
        return tamanho + 1;
    }
};

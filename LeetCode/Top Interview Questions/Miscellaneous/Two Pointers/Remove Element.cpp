class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //Corner case
        if((int)nums.size() == 0) return 0;
        int left = 0;
        int right = (int)nums.size() - 1;
        
        while(left < right){
            if(nums[left] == val){
                if(nums[right] == val){
                    right--;
                }else{
                    int temp = nums[left];
                    nums[left] = nums[right];
                    nums[right] = temp;
                    left++;
                    right--;
                }
            }else{
                left++;
            }
        }
        int answer = 0;
        while(answer < (int)nums.size() && nums[answer] != val){
            answer++;    
        } 
        
        return answer;
    }
};

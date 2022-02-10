class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int answer = -1;
        int currCount = 0;
        
        for(int i = 0; i < (int)nums.size(); i++){
            if(nums[i] == 0){
                answer = max(answer, currCount);
                currCount = 0;
            }else{
                currCount++;
            }
        }
        answer = max(answer, currCount);
        
        return answer;
    }
};

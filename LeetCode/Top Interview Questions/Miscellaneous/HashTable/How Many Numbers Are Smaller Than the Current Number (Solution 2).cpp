class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> answer;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        for(int i = 0; i < (int)nums.size(); i++){
            int target = nums[i];
            int low = 0, high = (int)sorted.size() - 1;
            int number = -1;
            while(low <= high){
                int mid = low + (high - low)/2;
                if(sorted[mid] < target){
                    number = mid;
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
            answer.push_back(number + 1);
        }
        
        return answer;
    }
};

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> answer;
        if(nums.size() == 0) return answer;
        
        if(nums.size() == 1){
            answer.push_back(to_string(nums[0]));
            return answer;
        }
        
        int left = 0, right = left + 1;
        int cursor = left;
        while(left < nums.size()){
            if((long long)nums[right] - (long long)nums[cursor] == 1LL){
                right++;
                cursor++;
            }else{
                if(left == right - 1){
                    answer.push_back(to_string(nums[left]));
                    left = right;
                    cursor = left;
                    right = right + 1;
                }else{
                    string curr = to_string(nums[left]) + "->" + to_string(nums[right - 1]);
                    answer.push_back(curr);
                    left = right;
                    right = right + 1;
                    cursor = left;
                }
            }
            if(right == nums.size()){
                if(left == right - 1){
                    answer.push_back(to_string(nums[left]));
                }else{
                    string curr = to_string(nums[left]) + "->" + to_string(nums[right - 1]);
                    answer.push_back(curr);
                }
                left = right;
            }
            
        }
        
        return answer;
    }
};

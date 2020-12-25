class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> answer;
        map<int,int> freq;
        for(int i = 0; i < (int)nums.size(); i++){
            freq[nums[i]]++;
        }
        for(int i = 0; i < (int)nums.size(); i++){
            int target = nums[i];
            int counter = 0;
            for(map<int,int>::iterator it = freq.begin(); it != freq.end(); it++){
                if(it->first >= target) break;
                else{
                    counter += it->second;
                }
            }
            answer.push_back(counter);
        }
        return answer;
    }
};

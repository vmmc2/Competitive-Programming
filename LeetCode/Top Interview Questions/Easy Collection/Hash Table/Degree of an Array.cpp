class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int> freq;
        map<int,int> firstOccur;
        map<int,int> lastOccur;
        int maximum = -1;
        int answer = 1e8;
        
        for(auto x : nums){
            freq[x]++;
            maximum = max(maximum, freq[x]);
        }
        for(int i = 0; i < (int)nums.size(); i++){
            if(firstOccur.find(nums[i]) == firstOccur.end()){
                firstOccur[nums[i]] = i;
            }
        }
        for(int i = (int)nums.size() - 1; i >= 0; i--){
            if(lastOccur.find(nums[i]) == lastOccur.end()){
                lastOccur[nums[i]] = i;
            }
        }
        for(map<int,int>::iterator it = freq.begin(); it != freq.end(); it++){
            if(it->second == maximum){
                answer = min(answer, lastOccur[it->first] - firstOccur[it->first] + 1);
            }
        }
        
        return answer;
    }
};

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int answer = 0;
        unordered_map<int,int> freq;
        for(auto x : nums){
            freq[x]++;
        }
        for(unordered_map<int,int>::iterator it = freq.begin(); it != freq.end(); it++){
            if(it->second == 1){
                answer += it->first;
            }
        }
        
        return answer;
    }
};

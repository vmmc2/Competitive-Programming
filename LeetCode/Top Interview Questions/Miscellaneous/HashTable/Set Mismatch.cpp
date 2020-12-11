class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> freq(n + 1, 0);
        vector<int> answer;
        
        for(auto x : nums){
            freq[x]++;    
        }
        int occur2;
        int missing;
        for(int i = 1; i <= n; i++){
            if(freq[i] == 0) missing = i;
            if(freq[i] == 2) occur2 = i;
        }
        answer.push_back(occur2);
        answer.push_back(missing);
        return answer;
    }
};

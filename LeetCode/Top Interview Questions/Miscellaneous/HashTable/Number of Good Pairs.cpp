class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> dict;
        for(int i = 0; i < (int)nums.size(); i++){
            dict[nums[i]]++;
        }
        int answer = 0;
        for(unordered_map<int,int>::iterator it = dict.begin(); it != dict.end(); it++){
            if(it->second > 1){
                int n = it->second;
                answer += (int)(n*(n-1))/2;
            }   
        }
        return answer;
    }
};

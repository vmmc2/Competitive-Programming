class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer;
        vector<bool> present(n + 1, false);
        
        for(auto x : nums){
            present[x] = true;
        }
        for(int i = 1; i <= n; i++){
            if(!present[i]) answer.push_back(i);
        }
            
        return answer;
    }
};

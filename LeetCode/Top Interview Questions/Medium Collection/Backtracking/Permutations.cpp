class Solution {
public:
    void helper(vector<int> &nums, vector<int> &permutation, vector<bool> &used, vector<vector<int>> &answer){
        if(permutation.size() == nums.size()){
            answer.push_back(permutation);
            return;
        }
        for(int i = 0; i < (int)nums.size(); i++){
            if(used[i] == true) continue;
            used[i] = true;
            permutation.push_back(nums[i]);
            helper(nums, permutation, used, answer);
            permutation.pop_back();
            used[i] = false;
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        if((int)nums.size() == 0) return answer; //conner case in which we received an empty array.
        
        int n = (int)nums.size();
        vector<bool> used(n, false);
        vector<int> permutation;
        
        helper(nums, permutation, used, answer);
        return answer;
    }
};

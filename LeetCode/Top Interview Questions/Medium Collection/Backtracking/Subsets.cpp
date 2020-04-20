class Solution {
public:
    void helper(int cursor, int n, vector<vector<int>> &answer, vector<int> &now, vector<int> &nums){
        if(cursor >= n){ //ja extrapolei
            answer.push_back(now);
            return;
        }
        helper(cursor + 1, n, answer, now, nums);
        now.push_back(nums[cursor]);
        helper(cursor + 1, n, answer, now, nums);
        now.pop_back();
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        int n = (int)nums.size();
        
        //treating the conner cases
        if(n == 0) return answer; //we received an empty vector as input.
        
        //treating the general cases
        vector<int> now;
        int cursor = 0;
        helper(cursor, n, answer, now, nums);
        return answer;
    }
};

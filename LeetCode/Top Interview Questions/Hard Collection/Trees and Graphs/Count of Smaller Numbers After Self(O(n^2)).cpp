class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> answer;
        //treating the corner case...
        if((int)nums.size() == 0) return answer;
        
        //treating the general cases...
        int n = (int)nums.size();
        answer.resize(n, 0);
        for(int i = 0; i < n; i++){
            int counter = 0;
            for(int j = i + 1; j < n; j++){
                if(j >= n) break;
                if(nums[j] < nums[i]) counter++;
            }
            answer[i] = counter;
        }
        return answer;
    }
};

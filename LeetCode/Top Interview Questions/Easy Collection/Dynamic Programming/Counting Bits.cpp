class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        
        for(int i = 0; i < (int)dp.size(); i++){
            if(i == 0){
                dp[i] = 0;
            }else{
                dp[i] = dp[i >> 1] + (((i & 1) == 1) ? 1 : 0);
            }
        }
        
        return dp;
    }
};

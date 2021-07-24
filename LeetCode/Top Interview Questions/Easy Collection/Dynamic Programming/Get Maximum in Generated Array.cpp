class Solution {
public:
    int getMaximumGenerated(int n) {
        int answer = 0;
        vector<int> dp(n + 1, 0);
        for(int i = 0; i < (int)dp.size(); i++){
            if(i == 0) dp[i] = 0;
            else if(i == 1) dp[i] = 1;
            else{
                if(i % 2 == 0){
                    dp[i] = dp[i/2];    
                }else{
                    dp[i] = dp[i/2] + dp[(i/2) + 1];
                }
            }
            answer = max(answer, dp[i]);
        }
        
        return answer;
    }
};

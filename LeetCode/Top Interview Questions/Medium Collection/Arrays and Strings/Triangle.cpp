class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = (int)triangle.size();
        vector<vector<int>> dp(m);
        int answer = 1e8;
        
        for(int i = 0, j = 1; i < m; i++, j++){
            dp[i].assign(j, 0);
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < (int)triangle[i].size(); j++){
                if(i == 0) dp[i][j] = triangle[i][j];
                else{
                   if(j == 0){
                       dp[i][j] = dp[i - 1][j] + triangle[i][j];
                   }else if(j == (int)triangle[i].size() - 1){
                       dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                   }else{
                       dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
                   }
                }
            }
        }
        for(int i = 0; i < (int)dp[m - 1].size(); i++){
            answer = min(answer, dp[m - 1][i]);
        }
        
        return answer;
    }
};

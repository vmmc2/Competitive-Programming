class Solution {
public:
    int dp[1001];
    int helper(int n){
        if(n == 1) return 0;
        if(dp[n] != -1) return dp[n];
        else{
            for(int i = 1; i * i <= n; i++){
                if(n % i == 0){
                    if(helper(n - i) == 0) return dp[n] = 1;
                }
            }
            return dp[n] = 0;
        }
    }
    bool divisorGame(int N) {
        memset(dp, -1, sizeof(dp));
        return helper(N);
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if((int)cost.size() <= 1) return 0;
        if((int)cost.size() == 2) return min(cost[0], cost[1]);
        
        int n = (int)cost.size();
        cost.push_back(0);
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i < n + 1; i++){
            dp[i] = min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]);
        }
        return dp[n];
    }
};

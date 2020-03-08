class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if((int)prices.size() == 0) return 0;
        int i = 0; //cursor pra indicar nossa venda do month atual
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        while(i < (int)prices.size() - 1){
            //descobrindo o valley
            while(i < (int)prices.size() - 1 && prices[i] >= prices[i+1])
                i++;
            valley = prices[i];
            //descobrindo o peak
            while(i < (int)prices.size() - 1 && prices[i] <= prices[i+1])
                i++;
            peak = prices[i];
            maxprofit += (peak - valley);
        }
        return maxprofit;
    }
};

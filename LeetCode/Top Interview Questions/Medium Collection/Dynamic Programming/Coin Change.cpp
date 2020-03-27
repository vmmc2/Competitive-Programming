class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //Otimizacao
        if((int)coins.size() == 0) return -1;
        sort(coins.begin(), coins.end()); //ordeno as moedas em ordem ascendente.
        int dp[amount + 1];
        for(int i = 0; i < amount + 1; i++){
            dp[i] = amount + 1;
        }
        dp[0] = 0; //eu preciso de 0 moedas pra fazer a quantia 0.
        for(int i = 0; i <= amount; i++){
            for(int j = 0; j < (int)coins.size(); j++){
                if(coins[j] <= i){ //checo para ver se a moeda que eu quero usar eh menor que a quantia q eu quero fazer 
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }else{
                    break; //nao tem sentido eu continuar procurando se a moeda eh maior do q a quantia q eu tenho
                }
            }
        }
        return dp[amount] > amount ? -1: dp[amount];
        
    }
};

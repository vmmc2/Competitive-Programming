//Time Complexity: O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pseudo = 0; //pode ser que eu n faca nenhuma transacao. tiro o maximo disso e de answer e retorno a resposta.
        int ans = -69;
        int minimo = 9999999999;
        for(int i = 0; i < (int)prices.size(); i++){
            if(i == 0){
                minimo = min(minimo, prices[i]); 
            }else{
                if(prices[i] - minimo > ans){
                    ans = prices[i] - minimo;
                }
                minimo = min(minimo, prices[i]);
            }
        }
        return max(pseudo, ans);
    }
};

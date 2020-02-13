class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //vou ter que fazer uma mesma operacao 32 vezes
        uint32_t ans = 0;
        uint32_t temp = 0;
        for(int i = 1; i <= 32; i++){
            temp = n & 1; //isso aqui serve para eu descobrir o bit menos significativo do numero n.
            n = n >> 1; //desloco o numero n de uma unidade para a direita.
            if(i == 1){
                ans = temp;
            }else{
                ans = ans << 1;
                ans = ans | temp;
            }
        }
        return ans;
    }
};

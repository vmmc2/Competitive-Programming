class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0; //variavel que vai guardar a resposta.
        //enquanto n nao tiver chegado a 0...
        while(n){
            count += (n & 1); //Isso aqui ta pegando cada bit do meu numero de 
            //de tras para frente e vai somar 1, se eu tiver um bit 1.
            n = n >> 1; //shift right: desloca os bits uma unidade para a direita
        }
        return count;
    }
};

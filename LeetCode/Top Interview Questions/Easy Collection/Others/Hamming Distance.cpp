class Solution {
public:
    int hammingDistance(int x, int y) {
        //Perceba que nesse caso, eu quero saber em quantas posicoes de bits, os bits de X e de Y sao distintos
        //a melhor escolha eh usar um Xor bit-a-bit. Pq? Pq o xor retorna 1 se os bits sao diferentes e 0 caso
        //contrario...
        //Faz o xor. O xor vai me dar um numero novo, nesse numero novo eu tenho que calcular quantos bits 1 tem.
        //A quantidade de bits 1 nesse novo numero representa qtd de bits diferentes entre X e Y
        int novo = x ^ y;
        int count = 0;
        while(novo){
            count += (novo & 1);
            novo = novo >> 1;
        }
        return count;
    }
};

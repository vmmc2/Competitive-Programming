public class Solution {
    public boolean isPowerOfThree(int n) {
        //Explicacao..
        //Pega o maior inteiro de 32 bit que eh uma potencia de 3: 1162261467
        //Se o numero n dado for uma potencia de 3, entao ele obrigatoriamente ele tem que dividir esse numero gigante.
        //Testa o resto pra ver se divide.
        return n > 0 && 1162261467 % n == 0;
    }
}

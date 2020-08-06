class Solution {
public:
    int countPrimes(int n) {
        //Resolvendo para os casos base.
        if(n == 0 || n == 1){
            return 0;
        }
        //Resolvendo para o caso geral: n >= 2.
        vector<bool> isPrime(n, true); // Inicialmente, assumo que todos os numeros sao primos.
        int primeCounter = 0;
        
        for(int i = 2; i * i < n; i++){
            if(isPrime[i] == true){
                for(int j = 2; j * i < n; j++){
                    isPrime[i * j] = false;
                }
            }
        }
        
        for(int i = 2; i < n; i++){
            if(isPrime[i] == true) primeCounter++;
        }
        
        return primeCounter;
    }
};

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // Corner case: Nao da para dividir o numero 0
        if(numerator == 0) return "0";
        
        string answer = "";
        
        if(numerator < 0 ^ denominator < 0) answer += "-";
        
        long num = abs(numerator*1L);
        long den = abs(denominator*1L);
        
        //Pegando a parte inteira da divisao...
        answer += to_string(num/den);
        
        //Checando se o meu resultado foi um inteiro ou se tem parte fracionaria.
        if(num % den == 0) return answer; //resultado da divisao eh um numero inteiro. Ja posso retornar o valor
        
        answer += "."; //tem que computar a parte fracionaria.
        
        map<long,long> mapa;
        
        for(long int r = num % den; r; r = r % den){
            if(mapa.count(r) > 0){
                answer.insert(mapa[r], 1, '(');
                answer += ")";
                break;
            }
            
            mapa[r] = answer.size();
            r = r * 10;
            
            answer += to_string(r/den);
        }
        
        return answer;
     }
};

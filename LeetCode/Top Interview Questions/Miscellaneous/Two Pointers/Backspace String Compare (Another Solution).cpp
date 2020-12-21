class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = (int)S.size() - 1, j = (int)T.size() - 1;
        int skipS = 0, skipT = 0; 
        //skipS -> qtd de caracteres que eu vou ter q skipar dps de pressionado o backspace.
        //skipT -> qtd de caracteres que eu vou ter q skipar dps de pressionado o backspace.
        while(i >= 0 || j >= 0){
            while(i >= 0){
                if(S[i] == '#'){skipS++; i--;}
                else if(skipS > 0){skipS--; i--;}
                else break;
            }
            while(j >= 0){
                if(T[j] == '#'){skipT++; j--;}
                else if(skipT > 0){skipT--; j--;}
                else break;
            }
            //Se os dois caracteres de fato nao sao iguais.
            if(i >= 0 && j >= 0 && S[i] != T[j]) return false;
            //Se tentarmos comparar um caractere e n tivermos nada no outro..
            if((i >= 0) != (j >= 0)) return false;
            i--;
            j--;
        }
        return true;
    }
};

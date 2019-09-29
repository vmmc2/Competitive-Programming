
class Solution {
public:
    void reverseString(vector<char>& s) {
        //Primeira coisa: Verificar se o tamanho da string eh par ou impar
        int tam = (int)s.size();
        if(tam % 2 == 0){//tamanho par
            int inicio = 0;
            int fim = (int)s.size() - 1;
            char aux;
            while(inicio < tam/2){
                aux = s[inicio];
                s[inicio] = s[fim];
                s[fim] = aux;
                inicio++;
                fim--;
            }
        }else{//tamanho impar
            int inicio = 0;
            int fim = (int)s.size() - 1;
            char aux;
            while(inicio < tam/2){
                aux = s[inicio];
                s[inicio] = s[fim];
                s[fim] = aux;
                inicio++;
                fim--;
            }
        }
    }
};

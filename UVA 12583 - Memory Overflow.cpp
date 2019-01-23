#include <bits/stdc++.h>

using namespace std;

int main(){
    int numcasos;
    int numpessoas, k;
    string pessoas;
    set <char> reconheco;
    vector <char> encontrei;
    map <char,int> dictionary;
    char auxiliar;
    int contador;
    scanf("%d", &numcasos);
    for(int i = 1; i <= numcasos; i++){
        contador = 0;
        cin >> numpessoas >> k >> pessoas;
        //processando as paradas dia apos dia
        for(int j = 0; j < (int)pessoas.length(); j++){
            auxiliar = pessoas[j];
            if(reconheco.find(auxiliar) == reconheco.end()){//quer dizer que eu encontrei alguem que eu n conhecia.
               //adiciono essa pessoa no meu set de pessoas que eu reconheco
               reconheco.insert(auxiliar);
               dictionary[auxiliar] = j; //to marcando o dia em que eu reconheci essa pessoa
            }
            else if(reconheco.find(auxiliar) != reconheco.end()){//eu ja encontrei com essa pessoa. agr sera q ta no range?
                if(j - dictionary[auxiliar] <= k){
                    contador++;
                }
                dictionary[auxiliar] = j;
            }
        }
        printf("Case %d: %d\n", i, contador);
        //tem que resetar as paradas apos cada caso de teste
        encontrei.clear();
        dictionary.clear();
        reconheco.clear();
    }
    return 0;
}

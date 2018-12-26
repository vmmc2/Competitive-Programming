#include <bits/stdc++.h>

using namespace std;

int main(){
    int numlinhas, numcolunas, i;
    vector <int> registro;
    int auxiliar, auxiliar2;
    int current, current2;
    int resposta;
    scanf("%d %d", &numlinhas, &numcolunas);
    while(numlinhas != 0){
        resposta = 0;
        
        for(i = 0; i < numcolunas; i++){
            scanf("%d", &auxiliar);
            registro.push_back(auxiliar);
        }
        for(i = 0; i < registro.size(); i++){
            if(i == 0){
                resposta += numlinhas - registro[i];
                auxiliar = resposta;
            }
            else{
                current = numlinhas - registro[i];
                current2 = numlinhas - registro[i-1];
                if(current > current2){
                    resposta += (current - current2);
                }
            }
        }
        printf("%d\n", resposta);
        registro.clear();
        scanf("%d %d", &numlinhas, &numcolunas);
    }
    return 0;
}

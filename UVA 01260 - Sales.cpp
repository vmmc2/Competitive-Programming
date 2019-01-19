#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#include <string.h>
#include <iomanip>

using namespace std;

int main(){
    vector <int> dados;
    vector <int> days;
    int size, aux;
    int contador;
    int answer;
    int numcasos;
    scanf("%d", &numcasos);
    for(int i = 1; i <= numcasos; i++){
        answer = 0;
        scanf("%d", &size);
        for(int j = 0; j < size; j++){
            scanf("%d", &aux);
            dados.push_back(aux);
        }
        for(int j = 1; j < (int)dados.size(); j++){
            contador = 0;
            for(int k = 0; k < j; k++){
                if(dados[k] <= dados[j]){
                    contador++;
                }
            }
            days.push_back(contador);
        }
        int tam = (int)days.size();
        for(int j = 0; j < tam; j++){
            answer += days[j];
        }
        printf("%d\n", answer);
        dados.clear();
        days.clear();
    }
    return 0;
}

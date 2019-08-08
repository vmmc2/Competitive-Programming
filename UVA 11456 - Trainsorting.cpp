#include <bits/stdc++.h>
#include <cmath>
#define pb push_back

using namespace std;

int main(){
    int numcasos;
    scanf("%d", &numcasos);
    for(int a = 1; a <= numcasos; a++){
        vector<int> cars;
        int numcarros;
        int aux;
        scanf("%d", &numcarros);
        for(int i = 0; i < numcarros; i++){
            scanf("%d", &aux);
            cars.pb(aux);
        }
        int n = numcarros;
        int lis[n];
        int lds[n];
        for(int i = 0; i < n; i++){
            lis[i] = 1;
            lds[i] = 1;
        }
        //COMPLEXITY: polinomial quadratica.
        //fazendo o lis primeiro: no caso o para cada lis[i] teremos a maior subsequencia crescente COMECANDO em i 
        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(cars[j] > cars[i]){
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }
        //fazendo o lds agr, mesmo esquema: para cada lis[i] teremos a maior subsequencia decrescente COMECANDO em i
        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(cars[j] < cars[i]){
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }
        //POR QUE ISSO DA CERTO? Tipo, suponha um carro na i-esima posicao, se eu fizer o lis[i], temos a maior subsequencia crescente comecando a partir
        //dele de carros com peso maior que o inicial, como esses carros ja estao ordenados por ordem de chegada, eh so eu pegar eles e jogar para a frente do trem. 
        //Agora, eu tbm tenho que fazer o lds[i] comecando no i-esimo carro, a questao eh que eu vou ter a subsequencia de todos os carros que chegaram dps dele e que
        //tem o peso menor que o dele. Finalmente, basta eu fazer a checagem do lis[i] + lds[i] - 1 para cada um dos i carros presentes no trem e selecionar o maior. Esse 
        //-1 serve para evitar a contagem dupla do carro inicial.
        //cabou-se
        int answer = 0;
        for(int i = 0; i < n; i++){
            answer = max(answer, lis[i] + lds[i] - 1);
        }
        printf("%d\n", answer);
    }
    return 0;
}

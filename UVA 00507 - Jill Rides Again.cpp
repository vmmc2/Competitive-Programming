#include <bits/stdc++.h>
#include <cmath>
#define pb push_back

using namespace std;

int main(){
    int numcasos;
    int numparadas;
    int aux;
    
    scanf("%d", &numcasos);
    for(int i = 1; i <= numcasos; i++){
        vector<int> valores;
        scanf("%d", &numparadas);
        for(int j = 1; j <= numparadas - 1; j++){
            scanf("%d", &aux);
            valores.pb(aux);
        }
        int inicio = 1;
        int fim = 1;
        int sum = 0;
        int answer = 0;
        int iniciof, finalf;
        for(int j = 0; j < (int)valores.size(); j++){
            sum += valores[j];
            if(sum >= 0){
                fim++;
            }
            if(sum > answer){
                answer = sum;
                iniciof = inicio;
                finalf = fim;
            }
            if(sum == answer && iniciof == inicio){
                iniciof = inicio;
                finalf = fim;
            }
            if(sum == answer && iniciof != inicio){
                if((fim - inicio) > (finalf - iniciof)){
                    iniciof = inicio;
                    finalf = fim;
                }
            }
            if(sum < 0){
                sum = 0;
                inicio = j + 2;
                fim = inicio;
            }
        }
        
        if(answer > 0){
            printf("The nicest part of route %d is between stops %d and %d\n", i, iniciof, finalf);
        }else{
            printf("Route %d has no nice parts\n", i);
        }
    }
    return 0;
}

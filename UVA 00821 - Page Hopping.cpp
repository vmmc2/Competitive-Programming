#include <bits/stdc++.h>
#include <cmath>
#define INF 999999

using namespace std;

int adjmat[110][110];

int main(){
    int a, b;
    int maior, menor;
    double sum;
    int divisor;
    int caso = 1;
    while(true){
        maior = -69;
        menor = 999999;
        set<int> registro;
        memset(adjmat, INF, sizeof adjmat);
        for(int i = 0; i <  110; i++){
            adjmat[i][i] = 0;
        }
        scanf("%d %d", &a, &b);
        if(a == 0 && b == 0){
            break;
        }
        if(a > maior){
            maior = a;
        }
        if(b > maior){
            maior = b;
        }
        if(a < menor){
            menor = a;
        }
        if(b < menor){
            menor = b;
        }
        adjmat[a][b] = 1;
        registro.insert(a);
        registro.insert(b);
        while(true){
            scanf("%d %d", &a, &b);
            if(a == 0 && b == 0){
                break;
            }else{
                registro.insert(a);
                registro.insert(b);
                adjmat[a][b] = 1;
                if(a > maior){
                    maior = a;
                }
                if(b > maior){
                    maior = b;
                }
                if(a < menor){
                    menor = a;
                }
                if(b < menor){
                    menor = b;
                }
            }
        }
        for(int k = menor; k <= maior; k++){
            for(int i = menor; i <= maior; i++){
                for(int j = menor; j <= maior; j++){
                    adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j]);
                }
            }
        }
        sum = 0;
        for(int i = menor; i <= maior; i++){
            for(int j = menor; j<= maior; j++){
                if(adjmat[i][j] != 1061109567 && adjmat[i][j] > 0){
                    sum += adjmat[i][j];
                }
            }
        }
        int aux = (int)registro.size();
        divisor = aux * (aux - 1);
        sum = sum/divisor;
        printf("Case %d: average length between pages = %.3lf clicks\n", caso, sum);
        caso++;
    }
    
    return 0;
}

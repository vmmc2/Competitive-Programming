#include <bits/stdc++.h>

using namespace std;

int dp[1010][50];
int precos[1010];
int pesos[1010];
int numobjetos;

int knapsack(int i, int w, int cap){
    if(i >= numobjetos){
        return 0;
    }
    if(dp[i][w] != -1){
        return dp[i][w];
    }
    int p1, p2;
    if(w+pesos[i]<=cap){
        p1=precos[i]+knapsack(i+1,w+pesos[i],cap);
    }    
    else{
        p1=0;
    }    
    p2=knapsack(i+1,w,cap);
    
    return dp[i][w]=max(p1,p2);
}

int main(){
    int numcasos;
    int i, resposta;
    int pessoas, cap;
    scanf("%d", &numcasos);
    while(numcasos--){
        resposta = 0;
        scanf("%d", &numobjetos);
        for(i = 0; i < numobjetos; i++){
            scanf("%d %d", &precos[i], &pesos[i]);
        }
        scanf("%d", &pessoas);
        for(i = 0; i < pessoas; i++){
            scanf("%d", &cap);
            memset(dp, -1, sizeof(dp));
            resposta += knapsack(0, 0, cap);
        }
        printf("%d\n", resposta);
    }
    return 0;
}

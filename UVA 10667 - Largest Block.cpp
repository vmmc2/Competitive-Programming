#include <bits/stdc++.h>
#include <cmath>
#define pb push_back
#define INF 999999

using namespace std;

int main(){
    int numcasos;
    int n;
    int numberblocks;
    int linhainicial, colunainicial, linhafinal, colunafinal;
    int sumrect;
    int maxsumrect;
    int i, j;
    int k, l;
    scanf("%d", &numcasos);
    for(int a = 1; a <= numcasos; a++){
        int dp[105][105];
        scanf("%d", &n); //tamanho da matriz...
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                dp[i][j] = 1;
            }
        }
        scanf("%d", &numberblocks); //descobrindo a quantidade de blocos que estao ocupados...
        
        //preenchendo os blocos e tal...
        for(int b = 1; b <= numberblocks; b++){
            scanf("%d %d %d %d", &linhainicial, &colunainicial, &linhafinal, &colunafinal);
            linhainicial--;
            linhafinal--;
            colunainicial--;
            colunafinal--;
            for(i = linhainicial; i <= linhafinal; i++){
                for(j = colunainicial; j <= colunafinal; j++){
                    dp[i][j] = -69999;
                }
            }
        }
        //playtime... rs 
        //montando a matriz de soma cumulativa
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(i > 0) dp[i][j] += dp[i - 1][j];
                if(j > 0) dp[i][j] += dp[i][j - 1];
                if(i > 0 && j > 0) dp[i][j] -= dp[i - 1][j - 1];
            }
        }
        //cabou-se... agora monta realiza a DP...
        maxsumrect = -127*100*100;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                for(k = i; k < n; k++){
                    for(l = j; l < n; l++){
                        sumrect = dp[k][l];
                        if(i > 0) sumrect -= dp[i - 1][l];
                        if(j > 0) sumrect -= dp[k][j - 1];
                        if(i > 0 && j > 0) sumrect += dp[i - 1][j - 1];
                        maxsumrect = max(maxsumrect, sumrect);
                    }
                }
            }
        }
        if(maxsumrect == -69999){
            printf("0\n");
        }else{
            printf("%d\n", maxsumrect);
        }
    }
    return 0;
}

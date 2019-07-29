#include <bits/stdc++.h>
#include <cmath>
#define pb push_back
#define INF -9999

using namespace std;

int main(){
    int numcasos;
    string lixeira;
    int ordem;
    int i, j, k, l;
    int maxrectsum;
    scanf("%d", &numcasos);
    for(int a = 1; a <= numcasos; a++){
        int dp[25][25];
        cin >> lixeira;
        ordem = (int)lixeira.length();
        for(i = 0; i < ordem; i++){ //preenchendo a primeira linha da matriz...
            if(lixeira[i] == '0'){
                dp[0][i] = INF;
            }else if(lixeira[i] == '1'){
                dp[0][i] = 1;
            }
        }
        //montando o resto da matriz...
        for(int b = 1; b < ordem; b++){
            cin >> lixeira;
            for(i = 0; i < ordem; i++){
                if(lixeira[i] == '1'){
                    dp[b][i] = 1;
                }else if(lixeira[i] == '0'){
                    dp[b][i] = INF;
                }
            }
        }
        //monta a DP
        for(i = 0; i < ordem; i++){
            for(j = 0; j < ordem; j++){
                if(i > 0) dp[i][j] += dp[i - 1][j];
                if(j > 0) dp[i][j] += dp[i][j - 1];
                if(i > 0 && j > 0) dp[i][j] -= dp[i - 1][j - 1];
            }
        }
        //Show Time, Bitches!
        maxrectsum = INF*25*25; //worst case scenario...
        for(i = 0; i < ordem; i++){
            for(j = 0; j < ordem; j++){ //initial coord
                for(k = i; k < ordem; k++){
                    for(l = j; l < ordem; l++){ //final coord
                        int rectsum = dp[k][l];
                        if(i > 0) rectsum -= dp[i - 1][l];
                        if(j > 0) rectsum -= dp[k][j - 1];
                        if(i > 0 && j > 0) rectsum += dp[i - 1][j - 1];
                        maxrectsum = max(maxrectsum, rectsum);
                    }
                }
            }
        }
        if(maxrectsum == -9999){
            printf("0\n");
        }else{
            printf("%d\n", maxrectsum);
        }
        if(a != numcasos){
            printf("\n");
        }
    }
    return 0;
}

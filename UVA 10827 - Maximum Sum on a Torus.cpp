#include <bits/stdc++.h>
#include <cmath>
#define pb push_back
#define INF 99999

using namespace std;

int main(){
    int numcasos;
    int n;
    int i, j, k, l;
    int maxrectsum, rectsum;
    scanf("%d", &numcasos);
    for(int a = 1; a <= numcasos; a++){
        scanf("%d", &n); // ordem da matriz
        int matriz[80][80];
        int dp[160][160];
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                scanf("%d", &dp[i][j]);
                dp[i + n][j] = dp[i][j + n] = dp[i + n][j + n] = dp[i][j];
            }
        }
        //faz a soma cumulativa...
        for(i = 0; i < 2*n; i++){
            for(j = 0; j < 2*n; j++){
                if(i > 0) dp[i][j] += dp[i - 1][j];
                if(j > 0) dp[i][j] += dp[i][j - 1];
                if(i > 0 && j > 0) dp[i][j] -= dp[i - 1][j - 1];
            }
        }
        //hora de achar o maior la
        maxrectsum = -100*100*100;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){ //initial coord
                for(k = i; k < n + i && k < 2*n; k++){
                    for(l = j; l < n + j && l < 2*n; l++){ // final coord
                        rectsum = dp[k][l];
                        if(i > 0) rectsum -= dp[i - 1][l];
                        if(j > 0) rectsum -= dp[k][j - 1];
                        if(i > 0 && j > 0) rectsum += dp[i - 1][j - 1];
                        maxrectsum = max(rectsum, maxrectsum);
                    }
                }
            }
        }
        printf("%d\n", maxrectsum);
    }
    return 0;
}

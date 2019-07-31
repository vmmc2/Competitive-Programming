#include <bits/stdc++.h>
#include <cmath>
#define pb push_back
#define INF 999999

using namespace std;

// 0 nao tem arvore
// 1 tem arvore
int main(){
    int m, n;
    int i, j, k, l;
    int dp[105][105];
    int maxrectsum;
    int rectsum;
    while(true){
        scanf("%d %d", &m, &n);
        if(m == 0 && n == 0){
            break;
        }
        //preprocessando a matriz...
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                scanf("%d", &dp[i][j]);
                if(dp[i][j] == 1){
                    dp[i][j] = -6999;
                }else if(dp[i][j] == 0){
                    dp[i][j] = 1;
                }
                if(i > 0) dp[i][j] += dp[i - 1][j];
                if(j > 0) dp[i][j] += dp[i][j - 1];
                if(i > 0 && j> 0) dp[i][j] -= dp[i - 1][j - 1];
            }
        }
        //hora de achar a maior area
        maxrectsum = -127*100*100;
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){ //coord inicial
                for(k = i; k < m; k++){
                    for(l = j; l < n; l++){ //coord final
                        rectsum = dp[k][l];
                        if(i > 0) rectsum -= dp[i - 1][l];
                        if(j > 0) rectsum -= dp[k][j - 1];
                        if(i > 0 && j > 0) rectsum += dp[i - 1][j - 1];
                        maxrectsum = max(maxrectsum, rectsum);
                    }
                }
            }
        }
        if(maxrectsum == -6999){
            printf("0\n");
        }else{
            printf("%d\n", maxrectsum);
        }
    }
    return 0;
}

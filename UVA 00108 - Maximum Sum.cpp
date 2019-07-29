#include <bits/stdc++.h>
#include <cmath>
#define pb push_back

using namespace std;

int main(){
    int dp[105][105];
    int i, j, k, l;
    int n;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &dp[i][j]);
            if(i > 0) dp[i][j] += dp[i - 1][j];
            if(j > 0) dp[i][j] += dp[i][j - 1];
            if(i > 0 && j > 0) dp[i][j] -= dp[i - 1][j - 1];
        }
    }
    int maxrectsum = -127*100*100;
    int rectsum;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            for(k = i; k < n; k++){
                for(l = j; l < n; l++){
                    rectsum = dp[k][l];
                    if(i > 0) rectsum -= dp[i - 1][l];
                    if(j > 0) rectsum -= dp[k][j - 1];
                    if(i > 0 && j > 0) rectsum += dp[i - 1][j - 1];
                    maxrectsum = max(maxrectsum, rectsum);
                }
            }
        }
    }
    printf("%d\n", maxrectsum);
    return 0;
}

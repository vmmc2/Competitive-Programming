#include <bits/stdc++.h>
#include <cmath>
#define pb push_back
#define INF 99999

using namespace std;

int main(){
    int numcasos;
    int n, m;
    long long p;
    int i, j;
    int k, l;
    scanf("%d", &numcasos);
    for(int a = 1; a <= numcasos; a++){
        scanf("%d %d %lld", &n, &m, &p);
        long long dp[105][105];
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                scanf("%lld", &dp[i][j]);
                if(i > 0) dp[i][j] += dp[i - 1][j];
                if(j > 0) dp[i][j] += dp[i][j - 1];
                if(i > 0 && j > 0) dp[i][j] -= dp[i - 1][j - 1];
            }
        }
        //show time!
        long long area = 1;
        long long price;
        if(dp[0][0] > p) price = 0, area = 0;
        else price = dp[0][0];
        long long rectsum;
        int temp;
        int dx, dy;
        //printf("p: %d\n", p);
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){ //initial coord
                for(k = i; k < n; k++){
                    for(l = j; l < m; l++){//final coord
                        rectsum = dp[k][l];
                        if(i > 0) rectsum -= dp[i - 1][l];
                        if(j > 0) rectsum -= dp[k][j - 1];
                        if(i > 0 && j > 0) rectsum += dp[i - 1][j - 1];
                        //printf("i: %d -- k: %d -- j: %d -- l: %d\n", i, k, j, l);
                        dx = (k - i) + 1;
                        dy = (l - j) + 1;
                        temp = dx*dy;
                        //printf("temp: %d --- area: %d --- rectsum: %d --- p: %d\n", temp, area, rectsum, p);
                        if(temp > area && rectsum <= p){
                            area = temp;
                            price = rectsum;
                        }
                        if(temp == area && rectsum < price){
                            price = rectsum;
                        }
                    }
                }
            }
        }
        printf("Case #%d: %d %d\n", a, area, price);
    }
    return 0;
}

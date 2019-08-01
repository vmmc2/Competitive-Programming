#include <bits/stdc++.h>
#include <cmath>
#define pb push_back
#define INF 99999

using namespace std;

int main(){
    int n, m;
    int i, j, k, l;
    int sum;
    int ok = 0;
    while(scanf("%d %d", &n, &m) == 2){
        int dp[n][n];
        for(i = n - 1; i >= 0; i--){
            for(j = 0; j < n; j++){
                scanf("%d", &dp[i][j]);
            }
        }
        if(ok == 1){
            printf("\n");
        }
        //hora de fazer o pre-processamento...
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(i > 0) dp[i][j] += dp[i - 1][j];
                if(j > 0) dp[i][j] += dp[i][j - 1];
                if(i > 0 && j > 0) dp[i][j] -= dp[i - 1][j - 1];
            }
        }
        //show time!
        vector<int> answer;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){//start coord
                for(k = i; k < n; k++){
                    for(l = j; l < n; l++){//final coord
                        if((k - i) + 1 == m && (l - j) + 1 == m){
                            int temp = dp[k][l];
                            if(i > 0) temp -= dp[i - 1][l];
                            if(j > 0) temp -= dp[k][j - 1];
                            if(i > 0 && j > 0) temp += dp[i - 1][j - 1];
                            answer.pb(temp);
                        }
                    }
                }
            }
        }
        ok = 1;
        sum = 0;
        for(i = 0; i < (int)answer.size(); i++){
            sum += answer[i];
        }
        int ord = n - m + 1;
        int sentinela = 0;
        int newmatrix[ord][ord];
        for(i = 0; i < ord; i++){
            for(j = 0; j < ord; j++){
                newmatrix[i][j] = answer[sentinela];
                sentinela++;
            }
        }
        for(i = ord - 1; i >= 0; i--){
            for(j = 0; j < ord; j++){
                printf("%d\n", newmatrix[i][j]);
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}

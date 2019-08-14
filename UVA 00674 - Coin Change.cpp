#include <bits/stdc++.h>
#include <cmath>
#define pb push_back
#define INF 999999
#define pii pair<int,int>

using namespace std;

int main(){
    int coins_value[] = {1,5,10,25,50};
    int amount;
    while(scanf("%d", &amount) == 1){
        int table[6][amount + 1];
        for(int i = 0; i <= 5; i++){
            table[i][0] = 1;
        }
        for(int i = 1; i <= amount; i++){
            table[0][i] = 0;
        }
        for(int i = 1; i <= 5; i++){
            for(int j = 1; j <= amount; j++){
                if(coins_value[i - 1] > j){
                    table[i][j] = table[i - 1][j];
                }else{
                    table[i][j] = table[i - 1][j] + table[i][j - coins_value[i - 1]];
                }
            }
        }
        /*for(int i = 0; i <= 5; i++){
            for(int j = 0; j <= amount; j++){
                printf("%d ", table[i][j]);
            }
            printf("\n");
        }*/
        printf("%d\n", table[5][amount]);
    }
    return 0;
}

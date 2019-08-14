#include <bits/stdc++.h>
#include <cmath>
#define pb push_back
#define INF 999999
#define pii pair<int,int>

using namespace std;

int main(){
    long long coins[] = {1,5,10,25,50};
    int amount;
    while(scanf("%d", &amount) == 1){
        long long table[6][amount + 1];
        //pre-process...
        for(int i = 0; i <= 5; i++){
            table[i][0] = 1;
        }
        for(int i = 1; i <= amount; i++){
            table[0][i] = 0;
        }
        //show time porra!
        for(int i = 1; i <= 5; i++){
            for(int j = 1; j <= amount; j++){
                if(coins[i - 1] > j){
                    table[i][j] = table[i - 1][j];
                }else{
                    table[i][j] = table[i - 1][j] + table[i][j - coins[i - 1]];
                }
            }
        }
        if(table[5][amount] == 1){
            printf("There is only 1 way to produce %d cents change.\n", amount);
        }else if(table[5][amount] > 1){
            printf("There are %lld ways to produce %d cents change.\n", table[5][amount], amount);
        }
    }
    
    return 0;
}

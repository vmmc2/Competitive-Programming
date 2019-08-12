#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#define pb push_back
#define pii pair<int,int>
#define INF 999999

using namespace std;

int main(){
    int capacity, n;
    while(scanf("%d %d", &capacity, &n) == 2){
        vector<int> prices(n);
        vector<int> favour(n);
        int knapsack[1000][1000];
        if(capacity > 2000){
            capacity += 200;
            knapsack[n + 1][capacity + 1];
        }else{
            knapsack[n + 1][capacity + 1];
        }
        //printf("capacity: %d\n", capacity);
        for(int i = 0; i < n; i++){
            scanf("%d %d", &prices[i], &favour[i]);
        }
        //pre-processing the knapsack
        for(int i = 0; i <= n; i++){
            knapsack[i][0] = 0;
        }
        for(int i = 0; i <= capacity; i++){
            knapsack[0][i] = 0;
        }
        //show-time
        //tem que atentar para os indices desse ngc!!!!!!!
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= capacity; j++){
                if(prices[i - 1] > j){
                    knapsack[i][j] = knapsack[i - 1][j];
                }else{
                    knapsack[i][j] = max(knapsack[i - 1][j], favour[i - 1] + knapsack[i - 1][j - prices[i - 1]]);
                }
            }
        }
        /*for(int i = 0; i <= n; i++){
            for(int j = 0; j <= capacity; j++){
                printf("%d ", knapsack[i][j]);
            }
            printf("\n");
        }*/
        printf("%d\n", knapsack[n][capacity]);
    }
    return 0;
}

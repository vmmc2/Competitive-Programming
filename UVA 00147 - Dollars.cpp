#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <sstream>
#define pb push_back
#define INF 999999
#define pii pair<int,int>

using namespace std;

int main(){
    long long coins[] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
    double amount;
    while(scanf("%lf", &amount) == 1){
        if(amount == 0.00) break;
        int new_amount  = (int)round((amount * 100));
        long long table[12][new_amount + 1];
        //pre-processing the dp...
        for(int i = 0; i <= 11; i++){
            table[i][0] = 1;
        }
        for(int i = 1; i <= new_amount; i++){
            table[0][i] = 0;
        }
        for(int i = 1; i <= 11; i++){
            for(int j = 1; j <= new_amount; j++){
                if(coins[i - 1] > j){
                    table[i][j] = table[i - 1][j];
                }else{
                    table[i][j] = table[i - 1][j] + table[i][j - coins[i - 1]];
                }
            }
        }
        printf("%6.2lf%17lld\n", amount, table[11][new_amount]);
    }
    return 0;
}

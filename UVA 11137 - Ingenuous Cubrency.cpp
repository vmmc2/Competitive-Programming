#include <bits/stdc++.h>
#include <sstream>
#include <cstdio>
#include <cmath>
#define pb push_back
#define INF 999999
#define pii pair<int,int>

using namespace std;

typedef long long ll;

int main(){
    //pre-processing part. 1 
    vector<ll> coins;
    ll aux;
    for(ll i = 1; i <= 21; i++){
        aux = i * i* i;
        coins.pb(aux);
    }
    //next...
    int amount;
    while(scanf("%d", &amount) == 1){
        ll table[22][amount + 1];
        //pre-processing... part.2 
        for(int i = 0; i <= 21; i++){
            table[i][0] = 1;
        }
        for(int i = 1; i <= amount; i++){
            table[0][i] = 0;
        }
        //show-time!
        for(int i = 1; i <= 21; i++){
            for(int j = 1; j <= amount; j++){
                if(coins[i - 1] > j){
                    table[i][j] = table[i - 1][j];
                }else{
                    table[i][j] = table[i - 1][j] + table[i][j - coins[i - 1]];
                }
            }
        }
        printf("%lld\n", table[21][amount]);
    }
    return 0;
}

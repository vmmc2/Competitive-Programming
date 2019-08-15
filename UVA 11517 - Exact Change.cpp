#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <cmath>
#define pb push_back
#define pii pair<int,int>
#define INF 99999999

using namespace std;

typedef long long ll;

int main(){
    int numcasos;
    int value, qtd;
    scanf("%d", &numcasos);
    for(int a = 1; a <= numcasos; a++){
        int target;
        scanf("%d", &target);
        int numcoins;
        scanf("%d", &numcoins);
        vector<ll> coins(numcoins);
        for(int i = 0; i < numcoins; i++){
            scanf("%lld", &coins[i]);
        }
        ll dp[21234];
        dp[0] = 0;
        for(int i = 1; i < 21234; i++){
            dp[i] = INF;
        }
        
        for(int j = 0; j < (int)coins.size(); j++){
          for(int i = 21233-coins[j]; i >= 0; i--){
              if(dp[i] != INF){
                  dp[i+coins[j]] = min(dp[i+coins[j]], dp[i] + 1);
              }
          }
        }
        for(int i = target; i <= 21234; i++){
            if(dp[i] < INF){
                value = i;
                qtd = dp[i];
                break;
            }
        }
        printf("%d %d\n", value, qtd);
    }
    return 0;
}

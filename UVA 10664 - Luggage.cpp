#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <sstream>
#define pb push_back
#define INF 999999

using namespace std;

int main(){
    //Fast I/O 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numcasos;
    int n;
    string lixeira;
    cin >> numcasos;
    cin.ignore();
    for(int a = 1; a <= numcasos; a++){
        //parsing the string...
        getline(cin, lixeira);
        stringstream ss(lixeira);
        int aux;
        vector<int> itens;
        while(ss >> aux){
            itens.pb(aux);
        }
        //cin.ignore();
       /* for(int i = 0; i < (int)itens.size(); i++){
            printf("%d ", itens[i]);
        }*/
        //begin!
        int n = (int)itens.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += itens[i];
        }
        //printf("sum: %d\n", sum);
        if(sum % 2 != 0){
            printf("NO\n");
            continue;
        }
        int W = sum/2;
        int dp[n + 1][W + 1];
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i <= W; i++){
            dp[0][i] = 0;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= W; j++){
                if(dp[i - 1][j] == 1){
                    dp[i][j] = 1;
                }else{
                    if(itens[i - 1] > j){
                        dp[i][j] = 0;
                    }else{
                        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - itens[i - 1]];
                    }
                }
            }
        }
        /*for(int i = 0; i < n + 1; i++){
            for(int j = 0; j < W + 1; j++){
                printf("%d ", dp[i][j]);
            }
            printf("\n");
        }*/
        if(dp[n][W]){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}

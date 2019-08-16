#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#include <iostream>
#define pb push_back
#define INF 999999
#define pii pair<int,int>

//OBS:. O codigo fornece o output esperado em todos os casos de teste mas devido a complexidade O(n2) recebe o veredicto TLE em alguns deles.

using namespace std;

typedef long long ll;

int main(){
    int n;
    scanf("%d", &n);
    int array[n];
    int dp[n];
    int predecessor[n];
    vector<int> answer;
    int i;
    for(i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    //pre-processing...
    for(i = 0; i < n; i++){
        dp[i] = 1;
        predecessor[i] = i;
    }
    //show-time!
    for(i = 1; i < n; i++){
        for(int j = 0; j <= i - 1; j++){
            if(array[i] - array[j] == 1){ //crescentes e consecutivos...
                if(dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    predecessor[i] = j;
                }
            }
        }
    }
    //temos que checar agr o meu ponto de partida para pegar os predecessores...
    int qtd = -69;
    int s; //indice de partida para o array de predecessores
    for(i = 0; i < n; i++){
        if(dp[i] > qtd){
            qtd = dp[i];
            s = i;
        }
    }
    for(i = s; i != predecessor[i]; i = predecessor[i]){
        answer.pb(i + 1);
    }
    answer.pb(i + 1);
    reverse(answer.begin(), answer.end());
    printf("%d\n", qtd);
    for(i = 0; i < (int)answer.size(); i++){
        printf("%d ", answer[i]);
    }
    return 0;
}

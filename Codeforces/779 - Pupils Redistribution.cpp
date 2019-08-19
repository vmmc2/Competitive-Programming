#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 999999
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numstudents, aux;
    int groupA[6] = {0,0,0,0,0,0};
    int groupB[6] = {0,0,0,0,0,0};
    cin >> numstudents;
    //pegando os dados para o groupA
    for(int i = 0; i < numstudents; i++){
        cin >> aux;
        groupA[aux] += 1;
    }
    //pegando os dados para o groupB
    for(int i = 0; i < numstudents; i++){
        cin >> aux;
        groupB[aux] += 1;
    }
    //checagem para ver se vai rolar ou nao
    for(int i = 0 ; i < 6; i++){
        int diff = abs(groupA[i] - groupB[i]);
        if(diff % 2 == 1){
            printf("-1\n");
            return 0;
        }
    }
    //continua...
    int contador = 0;
    for(int i = 0; i < 6; i++){
        int soma = groupA[i] + groupB[i];
        soma = soma/2;
        //printf("soma = %d\n", soma);
        int minimo = min(groupA[i], groupB[i]);
        int new_diff = abs(soma - minimo);
        contador += new_diff;
    }
    printf("%d\n", contador/2);
    return 0;
}

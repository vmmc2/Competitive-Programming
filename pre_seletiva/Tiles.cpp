#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#define pb push_back
#define INF 9999999
#define MOD 998244353

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int linhas, colunas;
    
    cin >> colunas >> linhas;
    ull matrix[linhas][colunas];
    matrix[0][0] = 4;
    for(int i = 1; i <= colunas - 1; i++){
        matrix[0][i] = 2;
    }
    for(int i = 1; i <= linhas - 1; i++){
        matrix[i][0] = 2;
    }
    for(int i = 1; i < linhas; i++){
        for(int j = 1; j < colunas; j++){
            matrix[i][j] = 1;
        }
    }
    ull answer = 4;
    for(int i = 1; i <= colunas - 1; i++){
        answer = (answer*matrix[0][i])%MOD;
    }
    for(int i = 1; i <= linhas - 1; i++){
        answer = (answer*matrix[i][0])%MOD;
    }
    cout << answer << "\n";
    return 0;
}

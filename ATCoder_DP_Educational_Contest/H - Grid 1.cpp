#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 999999;

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int linhas, colunas;
	cin >> linhas >> colunas;
	char matrix[linhas][colunas];
	ll dp[linhas][colunas];

	for(int i = 0; i < linhas; i++){
		for(int j = 0; j < colunas; j++){
			cin >> matrix[i][j];
			dp[i][j] = 0;
			if(matrix[i][j] == '#'){
				dp[i][j] = 0;
			}
		}
	}
	dp[0][0] = 1;
	//preprocessou a primeira linha...
	for(int i = 1; i < colunas; i++){
			if(matrix[0][i] == '#') continue;
			else{
				dp[0][i] = (dp[0][i - 1])%(1000000007);
			}
	}
	//preprocessou a primeira coluna
	for(int i = 1; i < linhas; i++){
		if(matrix[i][0] == '#') continue;
		else{
			dp[i][0] = (dp[i - 1][0])%(1000000007);
		}
	}
	for(int i = 1; i < linhas; i++){
		for(int j = 1; j < colunas; j++){
			if(matrix[i][j] != '#'){
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%(1000000007);
			}
		}
	}
	printf("%lld\n", dp[linhas - 1][colunas - 1]);
	return 0;
}

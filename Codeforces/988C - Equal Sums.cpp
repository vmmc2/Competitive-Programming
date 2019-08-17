#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 999999;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int sentinela = 1;
	vector<tuple<int,int,int>> registro;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int tamanho_seq;
		cin >> tamanho_seq;
		vector<int> sequence(tamanho_seq);
		int sum = 0;
		for(int i = 0; i < tamanho_seq; i++){
			cin >> sequence[i];
			sum += sequence[i];
		}
		for(int i = 0; i < tamanho_seq; i++){
			int da_vez = sum - sequence[i];
			registro.pb(tuple<int,int,int>(da_vez, sentinela, i + 1));
		}
		sentinela++;
	}
	sort(registro.begin(), registro.end());
	int tam = (int)registro.size() - 1;
	int flag = 0;
	for(int i = 0; i <= tam - 1; i++){
		int sum1 = get<0>(registro[i]);
		int sum2 = get<0>(registro[i + 1]);
		int sequence1 = get<1>(registro[i]);
		int sequence2 = get<1>(registro[i + 1]);
		int index1 = get<2>(registro[i]);
		int index2 = get<2>(registro[i + 1]);
		if(sum1 == sum2 && sequence1 != sequence2){
			printf("YES\n");
			printf("%d %d\n", sequence1, index1);
			printf("%d %d\n", sequence2, index2);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}

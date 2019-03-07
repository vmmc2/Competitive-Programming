#include <bits/stdc++.h>

using namespace std;

int main(){
	int n = 0; //n eh o numero de clientes que vao vir visitar o cafe no dia n
	int i = 0;
	int hora = 0, minuto = 0;
	int cash = 0;
	pair <int,int> aux;
	map <pair<int,int>,int> cafe;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d %d", &hora, &minuto);
		aux.first = hora;
		aux.second = minuto;
		cafe[aux]++;
	}
	for(map<pair<int,int>,int>::iterator it = cafe.begin(); it != cafe.end(); ++it){
		if(it->second > cash){
			cash = it->second;
		}
	}
	printf("%d\n", cash);
	return 0;
}

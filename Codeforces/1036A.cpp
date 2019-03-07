#include <bits/stdc++.h>

using namespace std;

int main(){
	long long int n, k, novosvertices, i;
	long long int altura, qtdsecoes;
	//n eh o numero de vertices do grafico da funcao
	//k eh a area que queremos obter
	cin >> n >> k;
	novosvertices = (2*n)+1;
	qtdsecoes = n;
	if(k < qtdsecoes){
		cout << "1" << endl;
		return 0;
	}
	if(k % qtdsecoes == 0){
		altura = k/qtdsecoes;
		cout << altura << endl;
	}	
	else if(k % qtdsecoes != 0){
		altura = k/qtdsecoes;
		altura++;
		cout << altura << endl;
	}
	return 0;
}

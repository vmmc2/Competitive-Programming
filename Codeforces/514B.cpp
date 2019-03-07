#include <bits/stdc++.h>

using namespace std;

int main(){
	int n = 0; //eh a qtd de stormtroopers presentes no meu plano
	int i, hansolox = 0, hansoloy = 0;
	int xst = 0, yst = 0;
	int dx = 0, dy = 0;
	int ok = 0;
	int cabou = 0;
	double cangular;
	map <double,int> stormtroopers;
	scanf("%d %d %d", &n, &hansolox, &hansoloy);
	for(i = 0; i < n; i++){
		scanf("%d %d", &xst, &yst);
		dx = xst - hansolox;
		dy = yst - hansoloy;
		if(dx != 0){
			cangular = (double) dy/dx;
			stormtroopers[cangular]++;
		}
		
		else{
			ok = 1;
		}
	}
	cabou = stormtroopers.size() + ok;
	cout << cabou << endl;

	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
	int tam, i;
	int contador = 0;
	string palavra = "";
	cin >> tam;
	for(i = 0; i < tam; i++){
		if(tam-contador == 0){
			break;
		}
		if(i == 0){
			palavra += "a";
			contador++;
		}
		if((i != 0 && i%2 == 0) && tam-contador >= 2){
			palavra += "aa";
			contador = contador +2;
		}		
		else if((i != 0 && i%2 == 0) && tam-contador < 2){
			palavra += "a";
			contador++;
		}
		else if((i != 0 && i%2 != 0) && tam-contador >= 2){
			palavra += "bb";
			contador = contador +2;
		}
		else if((i != 0 && i%2 != 0) && tam-contador < 2){
			palavra += "b";
			contador++;
		}
	}
	cout << palavra << endl;
	return 0;
}

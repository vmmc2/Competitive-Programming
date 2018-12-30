#include <bits/stdc++.h>

using namespace std;

void Cartas(int qtd);//prototipo da funcao

int main() {
    int qtd;
    cin >> qtd;
    while(qtd != 0){
        Cartas(qtd);
        cin >> qtd;
    }
	return 0;
}

void Cartas(int qtd){
    int i, auxiliar;
    queue <int> fila;
    for(i = 1; i <= qtd; i++){
        fila.push(i);
    }
    //comecou a brincadeira
    cout << "Discarded cards:";
    for(i = 1; i <= qtd-1; i++){
        if(i == qtd-1){
            cout << " " <<fila.front();
        }
        else{
            cout << " " << fila.front() << ",";
        }
        fila.pop();
        auxiliar = fila.front();
        fila.pop();
        fila.push(auxiliar);
    }
    cout << "\nRemaining card: " << fila.front() << "\n";
    fila.pop();
}

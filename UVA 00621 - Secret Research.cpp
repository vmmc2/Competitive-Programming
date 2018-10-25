#include <bits/stdc++.h>

using namespace std;

int main(){
    int tam;
    int numcasos;
    string aux;
    scanf("%d", &numcasos);
    while(numcasos--){
        cin >> aux;
        tam = aux.length();
        if(aux == "1" || aux == "78" || aux == "4"){
            printf("+\n");
        }
        else if(aux[tam-2] == '3' && aux[tam-1] == '5'){
            printf("-\n");
        }
        else if(aux[0] == '9' && aux[tam-1] == '4'){
            printf("*\n");
        }
        else if(aux[0] == '1' && aux[1] == '9' && aux[2] == '0'){
            printf("?\n");
        }
        else{
            printf("+\n");
        }
    }
    return 0;
}

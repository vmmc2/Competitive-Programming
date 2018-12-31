#include <bits/stdc++.h>

using namespace std;

int main(){
    int numpessoas, numcomandos;
    deque <int> fila;
    char comando;
    int auxiliar, auxiliar2;
    int j = 1;
    scanf("%d %d", &numpessoas, &numcomandos);
    while(numpessoas != 0 && numcomandos != 0){
        //montando a fila
        printf("Case %d:\n", j);
        for(int i = 1; i <= numpessoas && i <= 1000; i++){
            fila.push_back(i);
        }
        //simulando os comandos da fila
        for(int i = 1; i <= numcomandos; i++){
            scanf(" %c", &comando);
            if(comando == 'N'){
                auxiliar = fila.front();
                printf("%d\n", auxiliar);
                fila.pop_front();
                fila.push_back(auxiliar);
            }
            else if(comando == 'E'){
                scanf("%d", &auxiliar);
                for(int k = 0; k < fila.size(); k++){
                    if(fila[k] == auxiliar){
                        fila.erase(fila.begin()+k);
                    }
                }
                fila.push_front(auxiliar);
            }
        }
        j++;
        fila.clear();
        scanf("%d %d", &numpessoas, &numcomandos);
    }
    return 0;
}

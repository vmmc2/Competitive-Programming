#include <bits/stdc++.h>

using namespace std;

int main(){
    int numcasos;
    int numjobs, jobposition; //posicao ta indexada entre 0 e numjobs-1
    list <pair<int,int>> fila;
    pair<int,int> aux;
    int priority;
    int minutes;
    int maior = 1; //se maior for igual a 0, quer dizer q deu ruim
    scanf("%d", &numcasos);
    for(int i = 1; i <= numcasos; i++){
        minutes = 0;
        scanf("%d %d", &numjobs, &jobposition);
        for(int j = 0; j < numjobs; j++){
            scanf("%d", &priority);
            if(j == jobposition){
                fila.push_back({priority, 1});
            }
            else{
                fila.push_back({priority, 0});
            }
        }
        while(true){
            aux = fila.front();
            maior = 1;
            for(list <pair<int,int>>:: iterator it = fila.begin(); it != fila.end(); it++){
                if(it->first > aux.first){
                    maior = 0;
                }
            }
            if(maior == 0){
                fila.pop_front();
                fila.push_back(aux);
            }
            else if(maior == 1){
                if(aux.second == 1){
                    minutes++;
                    break;
                }
                else{
                    minutes++;
                    fila.pop_front();
                }
            }
        }
        printf("%d\n", minutes);
        fila.clear();
    }
    return 0;
}

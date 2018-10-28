#include <bits/stdc++.h>

using namespace std;

int main(){
    int incidencematrix[10][30];
    int aux[2];
    map <pair<int,int>,int> misera;
    int numcasos;
    int carajo;
    int n, m; // n = linhas e m = colunas
    int i, j, cont;
    bool sera;
    int dale = 0;
    scanf("%d", &numcasos);
    for(int trab = 1; trab <= numcasos; trab++){
        cont = 0;
        dale = 0;
        sera = true;
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                scanf("%d", &incidencematrix[i][j]);
            }
        }
        for(j = 0; j < m; j++){
            cont = 0;
            for(i = 0; i < n; i++){
                if(incidencematrix[i][j] == 1){
                    cont++;
                }
            }
            if(cont != 2){
                sera = false;
            }
        }
        if(sera == false){
            if(trab < numcasos){
                printf("No\n");
            }
            else if(trab == numcasos){
                printf("No\n");
            }
            continue;
        }
        //checando a prox condicao: se chegar nesse ponto eh pq todas as colunas so tem 2 vertices
        for(j = 0; j < m; j++){
            carajo = 0;
            for(i = 0; i < n; i++){
                if(incidencematrix[i][j] == 1){
                    aux[carajo] = i;
                    carajo++;
                }
            }
            sort(aux, aux+2);
            misera[make_pair(aux[0],aux[1])]++;
        }
        for(map<pair<int,int>, int>::iterator it = misera.begin(); it != misera.end(); it++){
            if(it->second >= 2){
                sera = false;
            }
        }
        //acabou caralho
        if(sera){
            if(trab < numcasos){
                printf("Yes\n");
            }
            else if(trab == numcasos){
                printf("Yes\n");
            }
        }
        else{
            if(trab < numcasos){
                printf("No\n");
            }
            else if(trab == numcasos){
                printf("No\n");
            }
        }
        misera.clear();
        
    }
    return 0;
}

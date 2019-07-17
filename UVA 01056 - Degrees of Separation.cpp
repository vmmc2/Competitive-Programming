#include <bits/stdc++.h>
#include <cmath>
#define INF 9999999

using namespace std;

int adjmatrix[100][100];
int numvertices;

void preprocess(){
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            adjmatrix[i][j] = INF;
            if(i == j){
                adjmatrix[i][j] = 0;
            }
        }
    }
}

void floyd_warshall(){
    for(int k = 1; k <= numvertices; k++){
        for(int i = 1; i <= numvertices; i++){
            for(int j = 1; j <= numvertices; j++){
                adjmatrix[i][j] = min(adjmatrix[i][j], adjmatrix[i][k] + adjmatrix[k][j]);
            }
        }
    }
}

int main(){
    int numedges;
    string deonde, paraonde;
    int aux, flag, answer;
    int caso = 1;
    while(true){
        scanf("%d %d", &numvertices, &numedges);
        if(numvertices == 0 && numedges == 0){
            break;
        }
        flag = 1; //suponho que o grafo eh conectado
        map<string,int> dicio;
        aux = 1;
        answer = -69;
        preprocess();
        for(int i = 1; i <= numedges; i++){
            cin >> deonde >> paraonde;
            if(dicio[deonde] == 0){
                dicio[deonde] = aux;
                aux++;
            }
            if(dicio[paraonde] == 0){
                dicio[paraonde] = aux;
                aux++;
            }
            adjmatrix[dicio[deonde]][dicio[paraonde]] = 1;
            adjmatrix[dicio[paraonde]][dicio[deonde]] = 1;
        }
        floyd_warshall();
        for(int i = 1; i <= numvertices; i++){
            for(int j = 1; j <= numvertices; j++){
                if(adjmatrix[i][j] == INF){
                    flag = 0;
                }
                if(adjmatrix[i][j] > answer && adjmatrix[i][j] != INF){
                    answer = adjmatrix[i][j];
                }
            }
        }
        if(flag == 0){
            printf("Network %d: DISCONNECTED\n", caso);
        }else{
            printf("Network %d: %d\n", caso, answer);
        }
        caso++;
        printf("\n");
    }
    return 0;
}

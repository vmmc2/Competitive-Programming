#include <bits/stdc++.h>
#include <cmath>
#define INF 0xffffff

using namespace std;

int adjmatrix[210][210];

void preprocess(){
    for(int i = 1; i < 210; i++){
        for(int j = 1; j < 210; j++){
            if(i == j){
                adjmatrix[i][j] = 0;
            }else{
                adjmatrix[i][j] = -1;
            }
        }
    }
}

int main(){
    int numvertices, numedges;
    int sentinela;
    string deonde, paraonde;
    string partida, chegada;
    int x, y;
    int weight;
    int scenario = 1;
    while(true){
        scanf("%d %d", &numvertices, &numedges);
        if(numvertices == 0 && numedges == 0){
            break;
        }
        preprocess();
        sentinela = 1;
        map<string,int> dictionary;
        for(int i = 0; i < numedges; i++){
            cin >> deonde >> paraonde >> weight;
            if(dictionary[deonde] == 0){
                dictionary[deonde] = sentinela;
                sentinela++;
            }
            if(dictionary[paraonde] == 0){
                dictionary[paraonde] = sentinela;
                sentinela++;
            }
            //printf(" opa: %d %d weight = %d\n\n", dictionary[deonde], dictionary[paraonde], weight);
            x = dictionary[deonde];
            y = dictionary[paraonde];
            adjmatrix[x][y] = weight;
            adjmatrix[y][x] = adjmatrix[x][y];
        }
        //roda agora a variacao do floyd-warshall
        for(int k = 1; k <= numvertices; k++){
            for(int i = 1; i <= numvertices; i++){
                for(int j = 1; j <= numvertices; j++){
                    adjmatrix[i][j] = max(adjmatrix[i][j], min(adjmatrix[i][k], adjmatrix[k][j]));
                }
            }
        }
        printf("Scenario #%d\n", scenario);
        scenario++;
        cin >> partida >> chegada;
        printf("%d tons\n", adjmatrix[dictionary[partida]][dictionary[chegada]]);
        printf("\n");
    }
    return 0;
}

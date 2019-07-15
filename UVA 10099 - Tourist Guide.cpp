#include <bits/stdc++.h>

using namespace std;

int adjmat[110][110];

void preprocess(){
    for(int i = 0; i < 110; i++){
        for(int j = 0; j < 110; j++){
            adjmat[i][j] = -1;
        }
    }
}

int main(){
    int numvertices, numedges;
    int deonde, paraonde, peso;
    int partida, chegada, passengers;
    int scenario = 1;
    int answer;
    while(true){
        scanf("%d %d", &numvertices, &numedges);
        if(numvertices == 0 && numedges == 0){
            break;
        }
        preprocess();
        for(int i = 1; i <= numedges; i++){
            scanf("%d %d %d", &deonde, &paraonde, &peso);
            adjmat[deonde][paraonde] = peso;
            adjmat[paraonde][deonde] = peso;
        }
        scanf("%d %d %d", &partida, &chegada, &passengers);
        //roda o floydwarshall...
        for(int k = 1; k <= numvertices; k++){
            for(int i = 1; i <= numvertices; i++){
                for(int j = 1; j <= numvertices; j++){
                    adjmat[i][j] = max(adjmat[i][j], min(adjmat[i][k], adjmat[k][j]));
                }
            }
        }
        printf("Scenario #%d\n", scenario);
        answer = passengers/(adjmat[partida][chegada] - 1);
        if(passengers%adjmat[partida][chegada] > 0){
            answer++;
        }
        printf("Minimum Number of Trips = %d\n", answer);
        printf("\n");
        scenario++;
    }
    return 0;
}

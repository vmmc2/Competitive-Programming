#include <bits/stdc++.h>
#include <cmath>
#define pb push_back

using namespace std;

int main(){
    int numcasos;
    int numvertices, numedges;
    int deonde, paraonde; 
    long long peso, times;
    scanf("%d", &numcasos);
    for(int a = 1; a <= numcasos; a++){
        scanf("%d %d", &numvertices, &numedges);
        long long adjmat[120][120];
        long long tempo[120][120];
        for(int i = 0; i < 120; i++){
            for(int j = 0; j < 120; j++){
                adjmat[i][j] = 1LL<<60;
                tempo[i][j] = 1LL<<60;
            }
            adjmat[i][i] = tempo[i][i] = 0;
        }
        for(int i = 1; i <= numedges; i++){
            scanf("%d %d %d %d", &deonde, &paraonde, &times, &peso);
            if(times < tempo[deonde][paraonde] || times == tempo[deonde][paraonde] && peso < adjmat[deonde][paraonde]){
                adjmat[deonde][paraonde] = adjmat[paraonde][deonde] = peso;
                tempo[deonde][paraonde] = tempo[paraonde][deonde] = times;
            }
        }
        int numqueries;
        for(int k = 1; k <= numvertices; k++){
            for(int i = 1; i <= numvertices; i++){
                for(int j = 1; j <= numvertices; j++){
                    if(tempo[i][j] > tempo[i][k] + tempo[k][j]){
                        tempo[i][j] = tempo[i][k] + tempo[k][j];
                        adjmat[i][j] = adjmat[i][k] + adjmat[k][j];
                    }
                    else if(tempo[i][j] == tempo[i][k] + tempo[k][j] && adjmat[i][j] > adjmat[i][k] + adjmat[k][j]){
                        adjmat[i][j] = adjmat[i][k] + adjmat[k][j];
                    }
                }
            }
        }
        scanf("%d", &numqueries);
        for(int i = 1; i <= numqueries; i++){
            scanf("%d %d", &deonde, &paraonde);
            if(adjmat[deonde][paraonde] != 1LL<<60){
                printf("Distance and time to reach destination is %lld & %lld.\n", adjmat[deonde][paraonde], tempo[deonde][paraonde]);
            }else{
                printf("No path.\n");
            }
        }
        if(a != numcasos){
            printf("\n");
        }
    }
    return 0;
}

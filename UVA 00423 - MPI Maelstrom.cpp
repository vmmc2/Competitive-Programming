#include <bits/stdc++.h>
#include <cmath>
#define INF 1000000

using namespace std;

int adjmat[110][110];

int main(){
    int numvertices;
    int value;
    while(scanf("%d", &numvertices) == 1){
    for(int i = 0; i < numvertices; i++){
        adjmat[i][i] = 0;
    }
    for(int i = 0; i < numvertices; i++){
        for(int j = 0; j < numvertices; j++){
            if(i > j){
                if(scanf("%d", &value) == 1){
                    adjmat[i][j] = value;
                    adjmat[j][i] = value;
                }else{
                    adjmat[i][j] = INF;
                    adjmat[j][i] = INF;
                    scanf("%*c");
                }
            }
        }
    }
    for(int k = 0; k < numvertices; k++){
        for(int i = 0; i < numvertices; i++){
            for(int j = 0; j < numvertices; j++){
                adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j]);
            }
        }
    }
    int answer = 0;
    for(int i = 1; i < numvertices; i++){
        answer = max(answer, adjmat[0][i]);
    }
    printf("%d\n", answer);
    }
    return 0;
}

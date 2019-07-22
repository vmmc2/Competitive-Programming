#include <bits/stdc++.h>
#include <cmath>
#define pb push_back

using namespace std;

struct island{
    int x, y;
    int radius;
};

int graph[105][105];

double dist(island a, island b){
    double deltax = abs(a.x - b.x);
    double deltay = abs(a.y - b.y);
    double x2 = deltax * deltax;
    double y2 = deltay * deltay;
    double dist = sqrt(x2 + y2);
    double answer = dist - a.radius - b.radius;
    return answer;
}

int main(){
    int k; //quantidade de dias que a jangada dura direto no mar 
    int m; //velocidade em milhas/dia
    int numvertices;
    island aux;
    while(scanf("%d %d", &k, &m) == 2){
        vector<island> pontos;
        scanf("%d %d %d", &aux.x, &aux.y, &aux.radius);
        pontos.pb(aux);
        scanf("%d %d %d", &aux.x, &aux.y, &aux.radius);
        pontos.pb(aux);
        //0 = ponto de partida  ------ 1 = ponto de chegada;
        scanf("%d", &numvertices);
        for(int a = 1; a <= numvertices; a++){
            scanf("%d %d %d", &aux.x, &aux.y, &aux.radius);
            pontos.pb(aux);
        }
        //hora de preprocessar o grafo
        for(int i = 0; i <= numvertices + 2; i++){
            for(int j = 0; j <= numvertices + 2; j++){
                if(i == j){
                    graph[i][j] = 0;
                }else{
                    graph[i][j] = 100000000;
                }
            }
        }
        int limite = k * m; //eh o limite que os caras podem navegar entre duas ilhas 
        //para que uma aresta possa existir entre duas ilhas, a distancia entre elas deve ser menor do que esse valor;
        
        //hora de montar o grafo na real
        for(int i = 0; i < (int)pontos.size() - 1; i++){
            for(int j = i + 1; j < (int)pontos.size(); j++){
                double distancia = dist(pontos[i], pontos[j]);
                if(distancia <= (double) limite){
                    graph[i][j] = graph[j][i] = 1;
                }
            }
        }
        //roda floyd-warshall...
        for(int k = 0; k <= numvertices + 2; k++){
            for(int i = 0; i <= numvertices + 2; i++){
                for(int j = 0; j <= numvertices + 2; j++){
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
        if(graph[0][1] < 100000000){
            printf("Larry and Ryan will escape!\n");
        }else{
            printf("Larry and Ryan will be eaten to death.\n");
        }
    }
    return 0;
}

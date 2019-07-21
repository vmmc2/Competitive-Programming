#include <bits/stdc++.h>
#include <cmath>
#define pb push_back

using namespace std;

struct point{
    int x, y;
};

double graph[110][110];

double dist(point a, point b){
    double deltax = abs(a.x - b.x);
    double deltay = abs(a.y - b.y);
    double x2 = deltax * deltax;
    double y2 = deltay * deltay;
    return sqrt(x2 + y2);
}

int main(){
    int numcasos;
    int numvertices;
    point aux;
    double distancia;
    scanf("%d", &numcasos);
    for(int a = 1; a <= numcasos; a++){
        for(int i = 0; i < 110; i++){
            for(int j = 0; j < 110; j++){
                graph[i][j] = 100000000;
                if(i == j){
                    graph[i][j] = 0;
                }
            }
        }
        vector<point> pontos;
        scanf("%d", &numvertices);
        for(int b = 1; b <= numvertices; b++){
            scanf("%d %d", &aux.x, &aux.y);
            pontos.pb(aux);
        }
        for(int i = 0; i < (int)pontos.size() - 1; i++){
            for(int j = i + 1; j < (int)pontos.size(); j++){
                distancia = dist(pontos[i], pontos[j]);
                if(distancia <= 10.0000){
                    graph[i][j] = graph[j][i] = min(graph[i][j], distancia);
                }
            }
        }
        for(int k = 0; k < numvertices; k++){
            for(int i = 0; i < numvertices; i++){
                for(int j = 0; j < numvertices; j++){
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
        double answer = 0;
        for(int i = 0; i < numvertices; i++){
            for(int j = 0; j < numvertices; j++){
                if(graph[i][j] > answer){
                    answer = graph[i][j];
                }
            }
        }
        if(answer == 100000000.0000){
            printf("Case #%d:\nSend Kurdy\n", a);
        }else{
            printf("Case #%d:\n%.4lf\n", a, answer);
        }
        printf("\n");
    }
    return 0;
}

#include <bits/stdc++.h>
#define INF 99999999
#define MAXN 100000

using namespace std;

typedef pair<int,int> pii;
int visitados[MAXN];
int distancia[MAXN];
vector<pii> adjlist[MAXN];

void preprocess(){
    for(int i = 0; i < MAXN; i++){
        visitados[i] = 0;
        distancia[i] = INF;
        adjlist[i].clear();
    }
}

void dijkstra(int s, int n){
    int davez;
    for(int i = 0; i < n; i++){
        distancia[i] = INF;
    }
    distancia[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>>fila;
    fila.push(pii(distancia[s], s));
    while(true){
        davez = -1;
        while(!fila.empty()){
            int atual = fila.top().second;
            fila.pop();
            if(visitados[atual] == 0){
                davez = atual;
                break;
            }
        }
        if(davez == -1) break;
        visitados[davez] = 1;
        
        for(int i = 0; i < (int)adjlist[davez].size(); i++){
            int dist = adjlist[davez][i].first;
            int atual2 = adjlist[davez][i].second;
            if(distancia[atual2] > distancia[davez] + dist){
                distancia[atual2] = distancia[davez] + dist;
                fila.push(pii(distancia[atual2],atual2));
            }
        }
    }
}

int main(){
    int numcasos;
    int i, j, a, b, w;
    int n, m; // n = numero de vertices e m = numero de arestas
    int S, T;// S = vertice de partida e T = vertice de chegada
    scanf("%d", &numcasos);
    for(i = 1; i <= numcasos; i++){
        //A cada caso, reseta tudo
        preprocess();
        scanf("%d %d %d %d", &n, &m, &S, &T);
        //Montagem do grafo baseada nas arestas
        for(j = 1; j <= m; j++){
            scanf("%d %d %d", &a, &b, &w);
            adjlist[a].push_back(pii(w,b));
            adjlist[b].push_back(pii(w,a));
        }
        dijkstra(S, n);
        if(distancia[T] == INF){
            printf("Case #%d: unreachable\n", i);
        }
        else{
            printf("Case #%d: %d\n", i, distancia[T]);
        }
    }
    return 0;
}

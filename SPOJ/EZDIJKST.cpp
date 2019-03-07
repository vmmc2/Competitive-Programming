#include <bits/stdc++.h>
#define INF 9999999
#define MAXN 100000

using namespace std;

typedef pair<int,int> pii;
vector<pii> adjlist[MAXN];//representacao do grafo. o primeiro elemento do pair eh a distancia e 
//segundo elemento do pair eh o vertice de chegada daquela aresta especifica
int distancias[MAXN];

void preprocess(){
    for(int i = 0 ; i < MAXN; i++){
        distancias[i] = INF;
        adjlist[i].clear();
    }
}

void Dijkstra(int s){
    for(int i = 0; i < MAXN; i++){
        distancias[i] = INF;
    }
    distancias[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>>fila;
    fila.push({0,s});
    while(!fila.empty()){
        int dist, atualvertex;
        dist = fila.top().first;
        atualvertex = fila.top().second;
        fila.pop();
        if(dist > distancias[atualvertex]){
            continue;
        }
        for(int i = 0; i < (int)adjlist[atualvertex].size(); i++){
            int dist2, proxvertex;
            dist2 = adjlist[atualvertex][i].first;
            proxvertex = adjlist[atualvertex][i].second;
            if(distancias[proxvertex] > distancias[atualvertex] + dist2){
                distancias[proxvertex] = distancias[atualvertex] + dist2;
                fila.push({distancias[proxvertex], proxvertex});
            }
        }
    }
}

int main(){
    int numcasos;
    int vertex, edges;
    int i, j, a, b, w;
    int inicio, chegada;
    scanf("%d", &numcasos);
    for(i = 1; i <= numcasos; i++){
        preprocess();
        scanf("%d %d", &vertex, &edges);
        for(j = 1; j <= edges; j++){
            scanf("%d %d %d", &a, &b, &w);
            adjlist[a].push_back({w,b});
        }
        scanf("%d %d", &inicio, &chegada);
        Dijkstra(inicio);
        if(distancias[chegada] == INF){
            printf("NO\n");
        }
        else{
            printf("%d\n", distancias[chegada]);
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#include <cmath>
#define pb push_back
#define INF 9999999

using namespace std;

int dist[10110];
vector<pair<int,int>> adjlist[10110];
map<string,int> dicio;

void preprocess(){
    for(int i = 0; i < 10110; i++){
        adjlist[i].clear();
    }
}

void dijkstra(int s){
    memset(dist, INF, sizeof dist);
    dist[s] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        pair<int,int> front = pq.top();
        pq.pop();
        int d = front.first, u = front.second;
        if(d > dist[u]){
            continue;
        }
        for(int j = 0; j < (int)adjlist[u].size(); j++){
            pair<int,int> v = adjlist[u][j];
            if(dist[u] + v.second < dist[v.first]){
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }
}

int main(){
    int numcasos;
    int numvertices, vizinhos;
    int destino, peso;
    string str;
    int aux;
    int numtravels;
    string deonde, paraonde;
    scanf("%d", &numcasos);
    for(int a = 1; a <= numcasos; a++){
        aux = 1;
        scanf("%d", &numvertices);
        memset(dist, INF, 10110);
        preprocess();
        dicio.clear();
        for(int b = 1; b <= numvertices; b++){
            cin >> str;
            dicio[str] = aux;
            aux++;
            scanf("%d", &vizinhos);
            for(int c = 1; c <= vizinhos; c++){
                scanf("%d %d", &destino, &peso);
                adjlist[dicio[str]].push_back({destino, peso});
            }
        }
        scanf("%d", &numtravels);
        for(int d = 1; d <= numtravels; d++){
            memset(dist, INF, sizeof dist);
            cin >> deonde >> paraonde;
            dijkstra(dicio[deonde]);
            printf("%d\n", dist[dicio[paraonde]]);
        }
        printf("\n");
    }
    return 0;
}

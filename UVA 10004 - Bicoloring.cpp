#include <bits/stdc++.h>

using namespace std;

vector <int> adjlist[220];
int visitados[220];
int bipartite;

void preprocess(){
    for(int i = 0; i < 220; i++){
        adjlist[i].clear();
        visitados[i] = 2;
    }
}

void bipartite_check(int x){
    queue <int> fila;
    fila.push(x);
    while(!fila.empty() && bipartite){
        int u = fila.front();
        fila.pop();
        for(int i = 0; i < (int)adjlist[u].size(); i++){
            int now = adjlist[u][i];
            if(visitados[now] == 2){
                visitados[now] = 1 - visitados[u];
                fila.push(now);
            }
            else if(visitados[now] == visitados[u]){
                bipartite = 0;
                break;
            }
        }
    }
}

int main(){
    int a, b;
    int numvertices, numedges;
    while(true){
        bipartite = 1; //a cada caso de teste eu assumo que o grafo é bipartido e tento provar o contrario
        preprocess();
        scanf("%d", &numvertices);
        if(numvertices == 0)break;
        scanf("%d", &numedges);
        for(int i = 1; i <= numedges; i++){
            scanf("%d %d", &a, &b);
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }
        visitados[a] = 0;
        bipartite_check(a);
        if(bipartite == 1){
            printf("BICOLORABLE.\n");
        }else{
            printf("NOT BICOLORABLE.\n");
        }
    }
    return 0;
}

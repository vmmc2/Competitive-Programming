#include <bits/stdc++.h>

using namespace std;

vector<int>adjlist[330];
int visitados[330];
int bipartite;

void preprocess(){
    for(int i = 0; i < 330; i++){
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
    int numvertices;
    while(true){
        bipartite = 1; //assumo inicialmente que o grafo é bipartido
        scanf("%d", &numvertices);
        if(numvertices == 0)break;
        preprocess();
        while(true){
            scanf("%d %d", &a, &b);
            if(a == 0 && b == 0){
                break;
            }
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }
        visitados[1] = 0;
        bipartite_check(1);
        if(bipartite == 1){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}

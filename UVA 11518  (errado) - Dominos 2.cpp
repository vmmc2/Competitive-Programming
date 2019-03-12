#include <bits/stdc++.h>

using namespace std;

vector <int> adjlist[10110];
vector <int> pp;
int answer;
int visitados[10110];

void reset(){
    for(int i = 0; i < 10110; i++){
        adjlist[i].clear();
    }
}

void dfs(int x){
    visitados[x] = 1;
    answer++;
    for(int i = 0; i < (int)adjlist[x].size(); i++){
        int u = adjlist[x][i];
        if(visitados[u] == 0){
            dfs(u);
        }
    }
}

int main(){
    int aux;
    int a, b;
    int numcasos;
    int qtdvertices, arestas, pontospartida;
    scanf("%d", &numcasos);
    for(int i = 0; i < numcasos; i++){
        answer = 0;
        memset(visitados, 0, sizeof visitados);
        pp.clear();
        reset();
        scanf("%d %d %d", &qtdvertices, &arestas, &pontospartida);
        for(int j = 1; j <= arestas; j++){
            scanf("%d %d", &a, &b);
            adjlist[a].push_back(b);
        }
        for(int j = 0; j < pontospartida; j++){
            scanf("%d", &aux);
            pp.push_back(aux);
        }
        //Agora eu tenho que rodar uma dfs a partir de todos os pontos de partida para ver quantas peças de domino
        //foram derrubadas no total
        for(int i = 0; i < pontospartida; i++){
            aux = pp[i];
            dfs(aux);
        }
        printf("%d\n", answer);
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

vector<pair<int,long long int>> adjlist[510];
int visitados[510];
int numcidades, numarestas;
long long int bullseye;
int contador;

void dfs(int x){
    visitados[x] = 1;
    for(int i = 0; i < (int)adjlist[x].size(); i++){
        //printf("entrei\n");
        int u = adjlist[x][i].first;
        //printf("u -- visitados[u]: %d --- %d\n", u, visitados[u]);
        int target = adjlist[x][i].second;
        if(visitados[u] == 0 && target == bullseye){
            contador++;
            dfs(u);
        }
    }
}

int main(){
    int a, b;
    long long int peso;
    int answer;
    while(true){
        for(int i = 0; i < 510; i++){
            adjlist[i].clear();
        }
        memset(visitados, 0, sizeof visitados);
        bullseye = -9999999999999; //reseta lixeira a cada caso de teste
        answer = -1;
        scanf("%d %d", &numcidades, &numarestas);
        if(numcidades == 0 && numarestas == 0){
            break;
        }
        for(int i = 0; i < numarestas; i++){
            scanf("%d %d %lld", &a, &b, &peso);
            adjlist[a].push_back({b,peso});
            adjlist[b].push_back({a,peso});
            bullseye = max(bullseye, peso);
        }
        //printf("bullseye = %d\n", bullseye);
        //agora vamo ter que rodar a dfs
        for(int i = 1; i <= numcidades; i++){
            if(visitados[i] == 0){
                contador = 0;
                //printf("CHAMANDO DFS PARA O %d\n", i);
                dfs(i);
                //printf("\n\n");
                //printf("contador: %d\n", contador);
                answer = max(answer, contador);
            }
        }
        printf("%d\n", answer + 1);
    }
}

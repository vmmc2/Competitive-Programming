#include <bits/stdc++.h>

using namespace std;

vector <int> adjlist[110];//representacao do grafo
vector <int> order;
int visitados[110];

void dfs(int u){
    visitados[u] = 1;
    for(int j = 0; j < (int)adjlist[u].size(); j++){
        int v = adjlist[u][j];
        if(visitados[v] == 0){
            dfs(v);
        }
    }
    order.push_back(u);
    //printf("Dei pushback no %d\n", u);
}

int main(){
    int n, m;
    int i, j;//i = numero de tarefas. // j = numero de relacoes de dependencia
    while(1){
        scanf("%d %d", &i, &j);
        if(i == 0 && j == 0){
            break;
        }
        //montando as arestas do grafo
        for(int a = 1; a <= j; a++){
            scanf("%d %d", &n, &m);
            adjlist[n].push_back(m);
        }
        //rodando a dfs
        for(int a = 1; a <= i; a++){
            if(visitados[a] == 0){
                dfs(a);
            }
        }
        //printando
        for(int a = (int)order.size()-1; a >= 0; a--){
            if(a != 0){
                printf("%d ", order[a]);
             }
            else if(a==0){
                 printf("%d", order[a]);
            }
        }
        printf("\n");
        //zerando as estruturas a cada instancia do problema
        order.clear();
        for(int a = 0; a < 110; a++){
            visitados[a] = 0;
        }
        for(int a = 0; a < 110; a++){
            adjlist[a].clear();
        }
    }
    return 0;
}

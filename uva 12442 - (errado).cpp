#include <bits/stdc++.h>
#define  MAX 60000

using namespace std;

vector <int> adjlist[MAX];
int visitados[MAX];
int answer;
int contador;
int indice;

void dfs(int x){
    int u;
    visitados[x] = 1;
    contador++;
    for(int i = 0; i < (int)adjlist[x].size(); i++){
        u = adjlist[x][i];
        if(visitados[u] == 0){
            dfs(u);
        }
    }
}

void preprocess(){
    for(int a = 0; a < MAX; a++){
        adjlist[a].clear();
    }
}

int main(){
    int numcasos;
    int va, vb;
    int qtdvertices;
    scanf("%d", &numcasos);
    for(int i = 1; i <= numcasos; i++){
        answer = -1; //a cada novo caso de teste a gente reseta answer;
        scanf("%d", &qtdvertices);
        preprocess();
        for(int j = 1; j <= qtdvertices; j++){
            scanf("%d %d", &va, &vb);
            adjlist[va].push_back(vb);
        }
        for(int j = 1; j <= qtdvertices; j++){
            contador = 0;
            memset(visitados, 0, sizeof visitados);
            dfs(j);
            if(contador > answer){
                answer = contador;
                indice = j;
            }
        }
        printf("Case %d: %d\n", i, indice);
    }
    return 0;
}

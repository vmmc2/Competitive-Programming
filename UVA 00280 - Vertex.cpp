#include <bits/stdc++.h>
#define MAXN 120

using namespace std;

vector <int> adjlist[MAXN];
int visitados[MAXN];
int vertex;

void dfs(int x, int flag){
    int u;
    if(flag == 0){
        visitados[x] = 0;
    }
    else{
        visitados[x] = 1;
    }
    flag++;
    for(int i = 0; i < (int)adjlist[x].size(); i++){;
        u = adjlist[x][i];
        if(visitados[u] == 0){
            dfs(u, flag);
        }
    }
}

void preprocess(){
    for(int a = 0; a < MAXN; a++){
        adjlist[a].clear(); //apaga todas as arestas dos grafos anteriores
    }
}

int main(){
    int answer;
    int flag;
    int pontodepartida;
    int start;
    int finale;
    int qtd_dfs;
    while(scanf("%d", &vertex)){
        preprocess();
        if(vertex == 0){//Nesse caso não teremos mais nenhum grafo em questão. 
            break;
        }
        while(true){
            scanf("%d", &start);
                if(start == 0){
                    break;
                }
                while(true){
                    scanf("%d", &finale);
                    if(finale == 0){
                        break;
                    }
                    adjlist[start].push_back(finale);
                }
        }
        scanf("%d", &qtd_dfs);
        for(int i = 1; i <= qtd_dfs; i++){
            flag = 0;
            answer = 0;
            scanf("%d", &pontodepartida);
            dfs(pontodepartida, flag);
            for(int a = 1; a <= vertex; a++){
                if(visitados[a] == 0){
                    answer++;
                }
            }
            printf("%d", answer);
            for(int a = 1; a <= vertex; a++){
                if(visitados[a] == 0){
                    printf(" %d", a);
                }
            }
            printf("\n");
            memset(visitados, 0, sizeof visitados);//seta todos os  vertices para não visitados
        }
    }
    return 0;
}

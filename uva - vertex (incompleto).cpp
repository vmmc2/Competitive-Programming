#include <bits/stdc++.h>
#define MAXN 120

using namespace std;

vector <int> adjlist[MAXN];
int visitados[MAXN];

void preprocess(){
    memset(visitados, 0, sizeof visitados);//seta todos os  vertices para não visitados
    for(int a = 0; a < MAXN; a++){
        adjlist[a].clear(); //apaga todas as arestas dos grafos anteriores
    }
}

int main(){
    int vertex;
    int start;
    int final;
    int qtd_dfs;
    while(scanf("%d", &vertex)){
        if(vertex == 0){//Nesse caso não teremos mais nenhum grafo em questão. 
            break;
        }
        while(true){
            scanf("%d", &start){
                if(start == 0){
                    break;
                }
                while(true){
                    scanf("%d", &final);
                    if(final == 0){
                        break;
                    }
                    adjlist[start].push_back(final);
                }
            }
        }
        scanf("%d", &qtd_dfs);
        for(int i = 1; i <= qtd_dfs; i++){
            preprocess();
            
        }
        
        
        
    }
    return 0;
}

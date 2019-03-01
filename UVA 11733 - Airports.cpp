#include <bits/stdc++.h>
#define MAXV 10100
#define MAXE 100010
using namespace std;

struct edge{
    int a,b; // a = vertice de partida; b = vertice de chegada
    int weight;//peso da aresta
};
//Funcao para comparar as arestas baseando-se no peso
bool comp(edge a, edge b){
    return a.weight < b.weight;
}
//Estrutura de dados: Union-Find e suas funções
int dsu[MAXV];
int size[MAXV];

void preprocess(){
    for(int i = 0; i < MAXV; i++){
        dsu[i] = i;
        size[i] = 1;
    }
}
int root(int i){
    while(dsu[i] != i){
        dsu[i] = dsu[dsu[i]];
        i = dsu[i];
    }
    return i;
}
void weighted_union(int a, int b){
    int root_A = root(a);
    int root_B = root(b);
    if(root_A = root_B){
        return;
    }
    if(size[root_A] < size[root_B]){
        dsu[root_A] = dsu[root_B];
        size[root_B] += size[root_A];
    }
    else{
        dsu[root_B] = dsu[root_A];
        size[root_A] += size[root_B];
    }
}

int main(){
    vector<edge> arestas;
    int numcasos, i, j;
    int n, m, a;
    int partida, chegada, peso;
    int airports;
    int paist, paiend;
    int answer;
    //n = numero de vertices
    //m = numero de arestas
    //a = valor de construcao de um aeroporto
    scanf("%d", &numcasos);
    for(i = 1; i <= numcasos; i++){
        answer = 0;
        //o numero de aeroportos que eu tenho que por eh igual ao numero de componentes conexas
        preprocess();
        arestas.clear();
        scanf("%d %d %d", &n, &m, &a);
        airports = n;
        for(j = 1; j <= m; j++){
            scanf("%d %d %d", &partida, &chegada, &peso);
            arestas.push_back({partida,chegada,peso});
        }
        sort(arestas.begin(), arestas.end(), comp);
        /*for(j = 0; j < arestas.size(); j++){
            printf("vertices: %d %d - peso: %d\n", arestas[j].a, arestas[j].b, arestas[j].weight);
        }*/
        for(j = 0; j < m; j++){
            if(arestas[j].weight >= a){
                break;
            }
            paist = root(arestas[j].a);
            paiend = root(arestas[j].b);
            if(paist != paiend){
                answer += arestas[j].weight;
                dsu[paist] = dsu[paiend];
                if(--airports == 1){
                    break;
                }
            }
        }
        printf("Case #%d: %d %d\n", i, answer+airports*a, airports);
    }
    return 0;
}

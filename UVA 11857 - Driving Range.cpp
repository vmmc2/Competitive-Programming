#include <bits/stdc++.h>

using namespace std;

struct edge{
    int a, b;
    int weight;
};
vector <edge> edgelist;
vector <edge> answer;
vector <int> adjlist[1001000];
int dsu[1001000];
int size[1001000];
int visitados[1001000];

void dfs(int x){
    visitados[x] = 1;
    for(int i = 0; i < (int)adjlist[x].size(); i++){
        int u = adjlist[x][i];
        if(visitados[u] == 0){
            dfs(u);
        }
    }
}

void initialize(){
    for(int i = 0; i < 1001000; i++){
        dsu[i] = i;
        size[i] = 1;
        adjlist[i].clear();
    }
}

bool compare(edge aresta1, edge aresta2){
    return aresta1.weight < aresta2.weight;
}

int root(int i){
    while(dsu[i] != i){
        dsu[i] = dsu[dsu[i]];
        i = dsu[i];
    }
    return i;
}

bool find(int a, int b){
    int root_A = root(a);
    int root_B = root(b);
    if(root_A == root_B){
        return true;
    }else{
        return false;
    }
}

void weighted_union(int a, int b){
    int root_A = root(a);
    int root_B = root(b);
    if(root_A == root_B){
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
    int numcomponentes;
    edge auxiliar;
    int numvertices, numedges;
    while(true){
        initialize();
        memset(visitados, 0, sizeof visitados);
        numcomponentes = 0;
        scanf("%d %d", &numvertices, &numedges);
        if(numvertices == 0 && numedges == 0){
            break;
        }
        for(int i = 1; i <= numedges; i++){
            scanf("%d %d %d", &auxiliar.a, &auxiliar.b, &auxiliar.weight);
            adjlist[auxiliar.a].push_back(auxiliar.b);
            adjlist[auxiliar.b].push_back(auxiliar.a);
            edgelist.push_back(auxiliar);
        }
        //primeira coisa. checar se o grafo apresenta apenas uma unica componente.
        for(int i = 0; i < numvertices; i++){
            if(visitados[i] == 0){
                numcomponentes++;
                dfs(i);
            }
        }
        if(numcomponentes >= 2){
            printf("IMPOSSIBLE\n");
        }else{
            sort(edgelist.begin(), edgelist.end(), compare);
            for(int i = 0; i < (int)edgelist.size(); i++){
                if(find(edgelist[i].a, edgelist[i].b) == false){
                    weighted_union(edgelist[i].a, edgelist[i].b);
                    answer.push_back(edgelist[i]);
                }
            }
            int tammy = (int)answer.size() - 1;
            printf("%d\n", answer[tammy].weight);
        }
        //resetando as paradas
        edgelist.clear();
        answer.clear();
    }
    return 0;
}

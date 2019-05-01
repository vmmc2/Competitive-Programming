#include <bits/stdc++.h>

using namespace std;

struct edge{
    int a, b;
    int weight;
};

vector<edge> edgelist;
vector <int> graph[500];
int visitados[500];
int dsu[500];
int size[500];

void initialize(){
    for(int i = 0; i < 500; i++){
        graph[i].clear();
        visitados[i] = 0;
        dsu[i] = i;
        size[i] = 1;
    }
    edgelist.clear();
}

void dfs(int x){
    visitados[x] = 1;
    for(int i = 0; i < (int)graph[x].size(); i++){
        int u = graph[x][i];
        if(visitados[u] == 0){
            dfs(u);
        }
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

bool find(int a, int b){
    if(root(a) == root(b)){
        return true;
    }else{
        return false;
    }
}

int main(){
    int customst;
    int cost;
    int deuruim;
    edge auxiliar;
    string aux;
    string origem, chegada;
    int peso;
    int numvertices, numedges, k;
    while(true){
        customst = 0;
        deuruim = 0;
        initialize();
        map<string,int> dictionary;
        scanf("%d %d", &numvertices, &numedges);
        if(numvertices == 0 && numedges == 0){
            break;
        }
        k = 0;
        for(int i = 1; i <= numvertices; i++){
            cin >> aux;
            dictionary[aux] = k;
            k++;
        }
        //montagem do grafo
        for(int i = 1; i <= numedges; i++){
            cin >> origem >> chegada >> peso;
            auxiliar.a = dictionary[origem];
            auxiliar.b = dictionary[chegada];
            auxiliar.weight = peso;
            edgelist.push_back(auxiliar);
            graph[dictionary[origem]].push_back(dictionary[chegada]);
            graph[dictionary[chegada]].push_back(dictionary[origem]);
        }
        sort(edgelist.begin(), edgelist.end(), compare);
        cin >> origem;
        dfs(dictionary[origem]);
        //checa para ver se do vertice de partida eu consigo chegar a todos os outros
        for(int i = 0; i <= k-1; i++){
            if(visitados[i] == 0){
                deuruim = 1;
            }
        }
        if(deuruim == 1){
            printf("Impossible\n");
        }else{ //hora de rodar o kruskal
            for(int i = 0; i < (int)edgelist.size(); i++){
                if(find(edgelist[i].a, edgelist[i].b) == false){
                    weighted_union(edgelist[i].a, edgelist[i].b);
                    customst += edgelist[i].weight;
                }
            }
            printf("%d\n", customst);
        }
    }
    return 0;
}

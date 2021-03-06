#include <bits/stdc++.h>

using namespace std; 

struct edge{
    int a, b;
    int weight;
};
int dsu[10110];
int size[10110];
int ap[10110];

void initialize(){
    for(int i = 0; i < 10110; i++){
        dsu[i] = i;
        size[i] = 1;
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
    if(root(a) == root(b)){
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
    int air;
    int mstcost;
    edge aux;
    int numcasos;
    int numvertices, numedges, airports;
    scanf("%d", &numcasos);
    for(int i = 1; i <= numcasos; i++){
        memset(ap, 0, sizeof ap);
        initialize();
        air = 0;
        mstcost = 0;
        vector<edge> edgelist;
        scanf("%d %d %d", &numvertices, &numedges, &airports);
        for(int j = 1; j <= numedges; j++){
            scanf("%d %d %d", &aux.a, &aux.b, &aux.weight);
            edgelist.push_back(aux);
        }
        sort(edgelist.begin(), edgelist.end(), compare);
        //Hora de rodar o Kruskal
        for(int j = 0; j < (int)edgelist.size(); j++){
            if(find(edgelist[j].a, edgelist[j].b) == false){
                if(edgelist[j].weight < airports){
                    weighted_union(edgelist[j].a, edgelist[j].b);
                    mstcost += edgelist[j].weight;
                }else if(edgelist[j].weight >= airports){
                    air++;
                    mstcost += airports;
                    weighted_union(edgelist[j].a, edgelist[j].b);
                }
            }
        }
        for(int j = 1; j <= numvertices; j++){
            if(dsu[j] == j){
                air++;
                mstcost += airports;
            }
        }
        printf("Case #%d: %d %d\n", i, mstcost, air);
    }
    return 0;
}    

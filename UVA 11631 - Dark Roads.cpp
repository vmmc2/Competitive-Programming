#include <bits/stdc++.h>

using namespace std;

struct edge{
    int a, b;
    int weight;
};
vector <edge> edgelist;
int dsu[200100];
int size[200100];


void initialize(){
    for(int i = 0; i < 200100; i++){
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
    int numvertices, numedges;
    edge auxiliar;
    int custotal;
    int newcusto;
    while(true){
        newcusto = 0;
        custotal = 0;
        scanf("%d %d", &numvertices, &numedges);
        if(numvertices == 0 && numedges == 0){
            break;
        }
        initialize();
        for(int i = 1; i <= numedges; i++){
            scanf("%d %d %d", &auxiliar.a, &auxiliar.b, &auxiliar.weight);
            edgelist.push_back(auxiliar);
            custotal += auxiliar.weight;
        }
        sort(edgelist.begin(), edgelist.end(), compare);
        for(int i = 0; i < (int)edgelist.size(); i++){
            if(find(edgelist[i].a, edgelist[i].b) == false){
                weighted_union(edgelist[i].a, edgelist[i].b);
                newcusto += edgelist[i].weight;
            }
        }
        printf("%d\n", custotal - newcusto);
        edgelist.clear();
    }
    return 0;
}

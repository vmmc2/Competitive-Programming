#include <bits/stdc++.h>

using namespace std;

struct edge{
    int a, b;
    int weight;
};
int dsu[1010];
int size[1010];
vector<edge> edgelist;

bool compare(edge aresta1, edge aresta2){
    return aresta1.weight < aresta2.weight;
}

void initialize(){
    for(int i = 0; i < 1010; i++){
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
    vector<int>answer;
    edge auxiliar;
    int numvertices, numedges;
    while(true){
        scanf("%d %d", &numvertices, &numedges);
        if(numvertices == 0 && numedges == 0){
            break;
        }
        initialize();
        for(int i = 1; i <= numedges; i++){
            scanf("%d %d %d", &auxiliar.a, &auxiliar.b, &auxiliar.weight);
            edgelist.push_back(auxiliar);
        }
        sort(edgelist.begin(), edgelist.end(), compare);
        //hora de rodar o kruskal
        for(int i = 0; i < (int)edgelist.size(); i++){
            if(find(edgelist[i].a, edgelist[i].b) == false){
                weighted_union(edgelist[i].a, edgelist[i].b);
            }else{
                answer.push_back(edgelist[i].weight);
            }
        }
        if((int)answer.size() == 0){
            printf("forest\n");
        }else{
            printf("%d", answer[0]);
            for(int i = 1; i < (int)answer.size(); i++){
                printf(" %d", answer[i]);
            }
            printf("\n");
        }
        edgelist.clear();
        answer.clear();
    }
    return 0;
}

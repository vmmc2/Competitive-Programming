#include <bits/stdc++.h>
#include <cmath>

using namespace std;

struct edge{
    int a, b;
    int weight;
};

vector<edge> edgelist;
int dsu[1010];
int size[1010];

void initialize(){
    for(int i = 0; i < 1010; i++){
        dsu[i] = i;
        size[i] = 1;
    }
    edgelist.clear();
}

bool compare(edge aresta1, edge aresta2){
    return aresta1.weight < aresta2.weight;
}

int dist(int x1, int y1, int x2, int y2){
    int d = pow((x1-x2),2) + pow((y1-y2),2);
    return d;
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
    edge auxiliar;
    int numcasos;
    double roadcost, railroadcost;
    int x, y;
    int k;
    int numvertices, limite;
    int numstates;
    scanf("%d", &numcasos);
    for(int i = 1; i <= numcasos; i++){
        initialize();
        numstates = 1;
        k = 0;
        roadcost = 0;
        railroadcost = 0;
        vector<pair<int,int>> vertices;
        map<pair<int,int>,int> dictionary;
        scanf("%d %d", &numvertices, &limite);
        for(int j = 1; j <= numvertices; j++){
            scanf("%d %d", &x, &y);
            vertices.push_back({x,y}); //montando o vector de pair em que cada elemento eu tenho o pair (x,y)
            dictionary[{x,y}] = k; //fazendo o link entre o pair e um rotulo(inteiro) para o vertice
            k++;
        }
        //agora tem que calcular as distancias e tal
        for(int j = 0; j < (int)vertices.size() - 1; j++){
            for(int k = j + 1; k < (int)vertices.size(); k++){
                auxiliar.a = dictionary[vertices[j]];
                auxiliar.b = dictionary[vertices[k]];
                auxiliar.weight = dist(vertices[j].first, vertices[j].second, vertices[k].first, vertices[k].second);
                edgelist.push_back(auxiliar);
            }
        }
        sort(edgelist.begin(), edgelist.end(), compare);
        for(int j = 0; j < (int)edgelist.size(); j++){
            if(sqrt(edgelist[j].weight) > (double)limite){
                if(find(edgelist[j].a, edgelist[j].b) == false){
                    weighted_union(edgelist[j].a, edgelist[j].b);
                    railroadcost += (double)sqrt(edgelist[j].weight);
                    numstates += 1;
                }
            }else{
                if(find(edgelist[j].a, edgelist[j].b) == false){
                    weighted_union(edgelist[j].a, edgelist[j].b);
                    roadcost += (double)sqrt(edgelist[j].weight);
                }
            }
        }
        printf("Case #%d: %d %.lf %.lf\n", i, numstates, roadcost, railroadcost);
    }
    return 0;
}

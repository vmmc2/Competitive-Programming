#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int dsu[1000];
int size[1000];

struct point{
    int x, y;
};

struct edge{
    int a, b;
    int weight;
};

void initialize(){
    for(int i = 0; i < 1000; i++){
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

int dist(point p1, point p2){
    int deltax = abs(p1.x - p2.x);
    int deltay = abs(p1.y - p2.y);
    int dist = pow(deltax, 2) + pow(deltay, 2);
    return dist;
}

bool compare(edge aresta1, edge aresta2){
    return aresta1.weight < aresta2.weight;
}

int main(){
    int deonde, paraonde;
    int numcasos;
    int exhighways;
    int numvertices;
    point lixeira;
    edge porra;
    lixeira.x = -69;
    lixeira.y = -69;
    scanf("%d", &numcasos);
    while(numcasos--){
        initialize();
        vector<point> pontos;
        vector<pair<int,int>>answer;
        vector<edge> edgelist;
        pontos.push_back(lixeira);
        point auxiliar;
        scanf("%d", &numvertices);
        for(int j = 1; j <= numvertices; j++){
            scanf("%d %d", &auxiliar.x, &auxiliar.y);
            pontos.push_back(auxiliar);
        }
        int cont = 0;
        scanf("%d", &exhighways);
        for(int j = 1; j <= exhighways; j++){
            scanf("%d %d", &deonde, &paraonde);
            if(find(deonde,paraonde) == false){
                weighted_union(deonde, paraonde);
                cont++;
            }
        }
        if(cont == numvertices - 1){
            puts("No new highways need");
        }
        else{
            for(int j = 1; j < (int)pontos.size(); j++){
                for(int k = j + 1; k < (int)pontos.size(); k++){
                    porra.a = j;
                    porra.b = k;
                    porra.weight = dist(pontos[j], pontos[k]);
                    edgelist.push_back(porra);
                }
            }
            sort(edgelist.begin(), edgelist.end(), compare);
            for(int j = 0; j < (int)edgelist.size(); j++){
                if(find(edgelist[j].a, edgelist[j].b) == false){
                    weighted_union(edgelist[j].a, edgelist[j].b);
                    answer.push_back({edgelist[j].a, edgelist[j].b});
                }
            }
            //sort(answer.begin(), answer.end());
            for(int j = 0; j < (int)answer.size(); j++){
                printf("%d %d\n", answer[j].first, answer[j].second);
            }
        }
        if(numcasos){
            puts("");
        }
    }
    return 0;
}

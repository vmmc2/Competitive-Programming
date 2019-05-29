#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int dsu[600];
int size[600];

struct edge{
    int a, b;
    double weight;
};

struct point{
    int x, y;
};

double dist(point a, point b){
    double deltax = (double)abs(a.x - b.x);
    double deltay = (double)abs(a.y - b.y);
    double pseudo = pow(deltax, 2) + pow(deltay, 2);
    return sqrt(pseudo);
}

void initialize(){
    for(int i = 0; i < 600; i++){
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

bool compare(edge aresta1, edge aresta2){
    return aresta1.weight < aresta2.weight;
}

int main(){
    int numcasos;
    int numvertices, numcomponentes;
    int compinicial;
    scanf("%d", &numcasos);
    for(int i = 1; i <= numcasos; i++){
        vector<point> pontos;
        vector<edge> edgelist;
        vector<edge> answer;
        point aux;
        edge auxiliar;
        initialize();
        scanf("%d %d", &compinicial, &numvertices);
        for(int j = 1; j <= numvertices; j++){
            scanf("%d %d", &aux.x, &aux.y);
            pontos.push_back(aux);
        }
        for(int j = 0; j < (int)pontos.size() - 1; j++){
            for(int k = j + 1; k < (int)pontos.size(); k++){
                auxiliar.a = j;
                auxiliar.b = k;
                auxiliar.weight = dist(pontos[j], pontos[k]);
                edgelist.push_back(auxiliar);
            }
        }
        sort(edgelist.begin(), edgelist.end(), compare);
        int curedge = 0;
        for(int j = 0; j < (int)edgelist.size(); j++){
            if(curedge == numvertices - compinicial){
                break;
            }
            if(find(edgelist[j].a, edgelist[j].b) == false){
                weighted_union(edgelist[j].a, edgelist[j].b);
                answer.push_back(edgelist[j]);
                curedge++;
            }
        }
        int tamanho = (int)answer.size();
        printf("%.2lf", answer[tamanho - 1]);
        if(i != numcasos){
            printf("\n");
        }
    }
    return 0;
}

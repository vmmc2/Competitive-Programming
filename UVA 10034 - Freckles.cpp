#include <bits/stdc++.h>
#include <iomanip>
#include <cmath>

using namespace std;

struct edge{
    int a, b;
    double weight;
};

map<pair<double,double>,int> dictionary;
vector <edge> edgelist;
vector <pair<double,double>> registro;
int dsu[110];
int size[110];

double distancia(double xa, double ya, double xb, double yb){
    double deltax, deltay, dist;
    deltax = abs(xa - xb);
    deltay = abs(ya - yb);
    dist = sqrt(pow(deltax, 2) + pow(deltay, 2));
    return dist;
}

bool comp(edge aresta1, edge aresta2){
    return aresta1.weight < aresta2.weight;
}

void initialize(){
    for(int i = 0; i < 110; i++){
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
    }
    else{
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
    //lembrar de usar o set precision dps
    int numcasos, numvertices;
    edge auxiliar;
    double x, y;
    int l, m;
    double answer = 0;
    
    cin >> numcasos;
    for(int i = 1; i <= numcasos; i++){
        initialize();
        answer = 0;
        cin >> numvertices;
        int k = 0;
        for(int j = 1; j <= numvertices; j++){
            cin >> x >> y;
            registro.push_back({x,y});
            dictionary[{x,y}] = k; //fazendo a correspondencia de pair(coordenadas) para vertice 
            k++;
        }
        //calculando as arestas: determinando: a, b e weight
        for(l = 0; l < (int)registro.size() - 1; l++){
            for(m = l + 1; m < (int)registro.size(); m++){
                auxiliar.a = dictionary[registro[l]];
                auxiliar.b = dictionary[registro[m]];
                auxiliar.weight = distancia(registro[l].first, registro[l].second, registro[m].first, registro[m].second);
                edgelist.push_back(auxiliar);
            }
        }
        //dando sorte na lista de arestas para poder aplicar o kruskal
        sort(edgelist.begin(), edgelist.end(), comp);
        //rodando o kruskal
        for(int j = 0; j < (int)edgelist.size(); j++){
            if(find(edgelist[j].a, edgelist[j].b) == false){
                weighted_union(edgelist[j].a, edgelist[j].b);
                answer += edgelist[j].weight;
            }
        }
        printf("%.2lf\n", answer);
        if(i != numcasos){
            printf("\n");
        }
        //resetando as paradas
        registro.clear();
        dictionary.clear();
        edgelist.clear();
    }
    return 0;
}

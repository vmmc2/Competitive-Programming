#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

int dsu[1000];
int size[1000];

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
    if(root(a) == root(b)){
        return true;
    }else{
        return false;
    }
}

void weighted_union(int a, int b){
    int rootA = root(a);
    int rootB = root(b);
    if(rootA == rootB){
        return;
    }
    if(size[rootA] < size[rootB]){
        dsu[rootA] = dsu[rootB];
        size[rootB] += size[rootA];
    }else{
        dsu[rootB] = dsu[rootA];
        size[rootA] += size[rootB];
    }
}

struct point{
    int x;
    int y;
};

struct edge{
    int a, b;
    double weight;
};

double dist(point p1, point p2){
    double deltax = (double)(abs(p1.x - p2.x));
    double deltay = (double)(abs(p1.y - p2.y));
    double dist2 = pow(deltax, 2) + pow(deltay, 2);
    return sqrt(dist2);
}

bool compara(edge aresta1, edge aresta2){
    return aresta1.weight < aresta2.weight;
}

int main(){
    
    
    int numvertices;
    int existentcables;
    point auxiliar;
    edge aux;
    int num1, num2;
    point porra;
    double answer;
    while(cin >> numvertices){
        answer = 0.00;
        initialize();
        porra.x = -69;
        porra.y = -69;
        vector<point> dale;
        vector<edge> edgelist;
        dale.push_back(porra);
        for(int i = 1; i <= numvertices; i++){
            cin >> auxiliar.x >> auxiliar.y;
            dale.push_back(auxiliar);
        }
        cin >> existentcables;
        for(int i = 1; i <= existentcables; i++){
            cin >> num1 >> num2;
            weighted_union(num1, num2);
        }
        for(int i = 1; i < (int)dale.size() - 1; i++){
            for(int j = i + 1; j < (int)dale.size(); j++){
                aux.a = i;
                aux.b = j;
                aux.weight = dist(dale[i], dale[j]);
                edgelist.push_back(aux);
            }
        }
        sort(edgelist.begin(), edgelist.end(), compara);
        for(int i = 0; i < (int)edgelist.size(); i++){
            if(find(edgelist[i].a, edgelist[i].b) == false){
                weighted_union(edgelist[i].a, edgelist[i].b);
                answer += edgelist[i].weight;
            }
        }
        printf("%.2lf\n", answer);
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int dsu[10030];
int size[10030];

struct edge{
    int a;
    int b;
    int weight;
};

bool compare(edge aresta1, edge aresta2){
    return aresta1.weight > aresta2.weight;
}

void initialize(){
    for(int i = 0; i < 10030; i++){
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    edge auxiliar;
    int lixo;
    int answer;
    int numcasos;
    int numvertices, numedges;
    cin >> numcasos;
    for(int x = 0; x < numcasos; x++){
        initialize();
        answer = 0;
        vector <edge> edgelist;
        cin >> numvertices >> numedges;
        for(int i = 0; i < numedges; i++){
            cin >> auxiliar.a >> auxiliar.b >> auxiliar.weight;
            edgelist.push_back(auxiliar);
        }
        sort(edgelist.begin(), edgelist.end(), compare); //ordena as arestas da de maior peso para a de menor peso
        //roda o  Kruskal agr rs 
        for(int i = 0; i < (int)edgelist.size(); i++){
            if(find(edgelist[i].a, edgelist[i].b) == false){
                weighted_union(edgelist[i].a, edgelist[i].b);
            }else{
                answer += edgelist[i].weight;
            }
        }
        cout << answer << endl;
    }
    return 0;
}

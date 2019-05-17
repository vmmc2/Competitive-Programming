#include <bits/stdc++.h>

using namespace std;

int dsu[110];
int size[110];

struct edge{
    int a;
    int b;
    int weight;
};

bool compara(edge aresta1, edge aresta2){
    return aresta1.weight > aresta2.weight;
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numcasos;
    int numedges, numvertices;
    edge aux;
    edge answer;
    cin >> numcasos;
    for(int a = 1; a <= numcasos; a++){
        initialize();
        vector<edge> edgelist;
        cin >> numvertices >> numedges;
        for(int i = 1; i <= numedges; i++){
            cin >> aux.a >> aux.b >> aux.weight;
            edgelist.push_back(aux);
        }
        sort(edgelist.begin(), edgelist.end(), compara);
        for(int i = 0; i < (int)edgelist.size(); i++){
            if(find(edgelist[i].a, edgelist[i].b) == false){
                weighted_union(edgelist[i].a, edgelist[i].b);
                answer = edgelist[i];
            }
        }
        cout << "Case #" << a << ": " << answer.weight << endl;
    }
    return 0;
}

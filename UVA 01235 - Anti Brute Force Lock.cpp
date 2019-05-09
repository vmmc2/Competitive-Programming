#include <bits/stdc++.h>
#include <cmath>

struct edge{
    int a, b;
    int weight;
};
int dsu[600];
int size[600];

using namespace std;

int dist(string lock1, string lock2){
    int res = 0;
    for(int i = 0; i < 4; i++) {
        int x = lock1[i] - '0';
        int y = lock2[i] - '0';
        res += min(abs(x - y), 10 - abs(x - y));
    }
    return res;
}

void initialize(){
    for(int i = 0; i < 600; i++){
        size[i] = 1;
        dsu[i] = i;
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


bool compare(edge aresta1, edge aresta2){
    return aresta1.weight < aresta2.weight;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numcasos;
    edge dale1;
    int numvertices;
    string aux;
    int k;
    int mstcost;
    cin >> numcasos;
    for(int i = 0; i < numcasos; i++){
        int foi;
        int misera = 9999999;
        initialize();
        vector<string> registro;
        mstcost = 0;
        vector<edge> edgelist;
        //registro.push_back("0000");
        cin >> numvertices;
        for(int j = 1; j <= numvertices; j++){
            cin >> aux;
            registro.push_back(aux);
        }
        map<string, int>dictionary;
        dictionary["0000"] = 0;
        k = 1;
        for(int j = 0; j < (int)registro.size(); j++){
            dictionary[registro[j]] = k;
            k++;
        }
        for(int j = 0; j < (int)registro.size(); j++){
            foi = dist("0000", registro[j]);
            if(foi < misera){
                misera = foi;
                dale1.a = dictionary["0000"];
                dale1.b = dictionary[registro[j]];
                dale1.weight = misera;
            }
        }
        edgelist.push_back(dale1);
        //fazendo a equivalencia entre string e inteiro para poder rotular os vertices do grafo
        //cabou-se. hora de calcular as distancias entre cada par de vertices
        for(int j = 0; j < (int)registro.size() - 1; j++){
            for(int k = j + 1; k < (int)registro.size(); k++){
                dale1.a = dictionary[registro[j]];
                dale1.b = dictionary[registro[k]];
                dale1.weight = dist(registro[j], registro[k]);
                edgelist.push_back(dale1);
            }
        }
        //agr tem que dar sort na edgelist
        sort(edgelist.begin(), edgelist.end(), compare);
        //por fim, roda o kruskal...
        for(int j = 0; j < (int)edgelist.size(); j++){
            if(find(edgelist[j].a, edgelist[j].b) == false){
                weighted_union(edgelist[j].a, edgelist[j].b);
                mstcost += edgelist[j].weight;
            }
        }
        cout << mstcost << endl;
    }
    return 0;
}

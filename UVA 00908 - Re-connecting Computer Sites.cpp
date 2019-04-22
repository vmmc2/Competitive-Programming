#include <bits/stdc++.h>

using namespace std;

int dsu[1000010];
int size[1000010];

struct edge{
    int a, b;
    int weight;
};

bool compare(edge aresta1, edge aresta2){
    return aresta1.weight < aresta2.weight;
}

void initialize(){
    for(int i = 0; i < 1000010; i++){
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector <edge> answer1;
    vector <edge> edgelist;
    edge aux;
    int numvertices, newlines, original;
    int a1, a2;
    while(cin >> numvertices){
        initialize();
        a1 = 0;
        a2 = 0;
        for(int i = 1 ; i <= numvertices - 1; i++){
            cin >> aux.a >> aux.b >> aux.weight;
            answer1.push_back(aux);
            a1 = a1 + aux.weight;
        }
        cin >> newlines;
        for(int i = 1; i <= newlines; i++){
            cin >> aux.a >> aux.b >> aux.weight;
            edgelist.push_back(aux);
        }
        cin >> original;
        for(int i = 1; i <= original; i++){
            cin >> aux.a >> aux.b >> aux.weight;
            edgelist.push_back(aux);
        }
        sort(edgelist.begin(), edgelist.end(), compare);
        for(int i = 0; i < (int)edgelist.size(); i++){
            if(find(edgelist[i].a, edgelist[i].b) == false){
                a2 += edgelist[i].weight;
                weighted_union(edgelist[i].a, edgelist[i].b);
            }
        }
        cout << a1 << endl;
        cout << a2 << endl;
        cout << endl; //printando um fim de linha ao final de cada caso de teste.
        answer1.clear();
        edgelist.clear();
    }
    return 0;
}

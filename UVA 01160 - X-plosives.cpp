#include <bits/stdc++.h>

using namespace std;

int dsu[1010000];
int size[1010000];

struct edge{
    int a, b;
    int weight;
};

void initialize(){
    for(int i = 0; i < 1010000; i++){
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

vector <edge> edgelist;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int contador = 0;
    int deonde, paraonde;
    int peso = 1;
    edge auxiliar;
    initialize();
    while(cin >> deonde){
        if(deonde == -1){
            //cheguei no fim de um caso agora tem que printar as paradas
            for(int i = 0; i < (int)edgelist.size(); i++){
                if(find(edgelist[i].a, edgelist[i].b) == false){
                    weighted_union(edgelist[i].a, edgelist[i].b);
                }else{
                    contador++;
                }
            }
            cout << contador << endl;
            contador = 0;
            initialize();
            edgelist.clear();
        }
        else{
            cin >> paraonde;
            auxiliar.a = deonde;
            auxiliar.b = paraonde;
            auxiliar.weight = peso;
            edgelist.push_back(auxiliar);
        }
    }
    return 0;
}

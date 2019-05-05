#include <bits/stdc++.h>

using namespace std;
map<int, char> dictionary;
int dsu[50];
int size[50];
struct edge{
    int a, b;
    int weight;
};

bool compare(edge aresta1, edge aresta2){
    return aresta1.weight < aresta2.weight;
}

void initialize(){
    for(int i = 0; i < 50; i++){
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

int find(int a, int b){
    if(root(a) == root(b)){
        return true;
    }else{
        return false;
    }
}

bool comp2(edge aresta1, edge aresta2){
    if(aresta1.weight == aresta2.weight){
        if(aresta1.a == aresta2.a){
            return aresta1.b < aresta2.b;
        }
        return aresta1.a < aresta2.a;
    }
    return aresta1.weight < aresta2.weight;
}

void weighted_union(int a, int b){
    int roota = root(a);
    int rootb = root(b);
    if(roota == rootb){
        return;
    }
    if(size[roota] < size[rootb]){
        dsu[roota] = dsu[rootb];
        size[rootb] += size[roota];
    }else{
        dsu[rootb] = dsu[roota];
        size[roota] += size[rootb];
    }
}

void preprocess(){
    char dale = 'A';
    int auxiliar;
    for(int i = 0; i <= 25; i++){
        dictionary[i] = dale;
        auxiliar = (int)dale + 1;
        dale = (char)auxiliar;
    }
}

int main(){
    int pqp;
    char lixeira;
    edge aux;
    int numcasos;
    int numvertices;
    preprocess();
    scanf("%d", &numcasos);
    for(int i = 1; i <= numcasos; i++){
        initialize();
        map<pair<int,int>,int>jafoi;
        vector<edge> edgelist;
        vector<edge> answer;
        scanf("%d", &numvertices);
        //montando a lista de arestas (edgelist)
        for(int j = 0; j < numvertices; j++){
            for(int k = 0; k <numvertices; k++){
                scanf("%d%c", &aux.weight, &lixeira);
                //printf("%d\n", aux.weight);
                if(aux.weight != 0){
                    aux.a = j;
                    aux.b = k;
                    if(jafoi[{j,k}] == 0 || jafoi[{k,j}] == 0){
                        edgelist.push_back(aux);
                        jafoi[{j,k}] = 1;
                        jafoi[{k,j}] = 1;
                    }
                }
            }
        }
        //ve se a lista de arestas foi printada direitinho rsrs 
        sort(edgelist.begin(), edgelist.end(), compare);
        /*for(int j = 0; j < (int)edgelist.size(); j++){
            printf("entrei -- %c %c %d\n", dictionary[edgelist[j].a], dictionary[edgelist[j].b], edgelist[j].weight);
        }*/
        for(int j = 0; j < (int)edgelist.size(); j++){
            if(find(edgelist[j].a, edgelist[j].b) == false){
                weighted_union(edgelist[j].a, edgelist[j].b);
                answer.push_back(edgelist[j]);
            }
        }
        sort(answer.begin(), answer.end(), comp2);
        printf("Case %d:\n", i);
        for(int j = 0; j <(int)answer.size(); j++){
            printf("%c-%c %d\n",dictionary[answer[j].a], dictionary[answer[j].b], answer[j].weight);
        }
    }
    return 0;
}

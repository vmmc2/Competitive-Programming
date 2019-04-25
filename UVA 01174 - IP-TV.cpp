#include <bits/stdc++.h>

using namespace std;

struct edge{
    int a, b;
    int weight;
};
map<string, int> dictionary;
vector <edge> edgelist;
int dsu[2019];
int size[2019];

void initialize(){
    for(int i = 0; i < 2019; i++){
        dsu[i] = i;
        size[i] = 1;
    }
}

bool compare(edge aresta1, edge aresta2){
    return aresta1.weight < aresta2.weight;
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


int main(){
    edge auxiliar;
    string city1, city2;
    int numcasos;
    int k = 0;
    int numvertices, numedges, peso;
    int answer;
    scanf("%d", &numcasos);
    for(int i = 1; i <= numcasos; i++){
        initialize();
        k = 0;
        answer = 0;
        scanf("%d", &numvertices);
        scanf("%d", &numedges);
        for(int j = 1; j <= numedges; j++){
            cin >> city1 >> city2 >> peso;
            if(dictionary.find(city1) == dictionary.end()){
                dictionary[city1] = k;
                k++;
            }
            if(dictionary.find(city2) == dictionary.end()){
                dictionary[city2] = k;
                k++;
            }
            auxiliar.a = dictionary[city1];
            auxiliar.b = dictionary[city2];
            auxiliar.weight = peso;
            edgelist.push_back(auxiliar);
        }
        sort(edgelist.begin(), edgelist.end(), compare);
        //Pronto. Ja montei a lista de adjacencia. Agora tem que rodar o Kruskal rs 
        for(int j = 0; j < (int)edgelist.size(); j++){
            if(find(edgelist[j].a, edgelist[j].b) == false){
                weighted_union(edgelist[j].a, edgelist[j].b);
                answer += edgelist[j].weight;
            }
        }
        printf("%d\n", answer);
        if(i != numcasos){
            printf("\n");
        }
        //resetando as paradas
        edgelist.clear();
        dictionary.clear();
    }
    return 0;
}

#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int dsu[10000];
int size[10000];

void initialize(){
    for(int i = 0; i < 10000; i++){
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

struct edge{
  int a, b;
  int weight;
  int flag;
};

bool compare(edge xesque, edge dele){
    return xesque.weight < dele.weight;
}

int main(){
    int firstmst, secondmst;
    int price;
    int numcasos;
    int numvertices, numedges;
    scanf("%d", &numcasos);
    for(int i = 0; i < numcasos; i++){
        initialize();
        firstmst = 0;
        price = 0;
        secondmst = 99999999;
        vector<edge>edgelist;
        vector<edge>man;
        edge auxiliar;
        scanf("%d %d", &numvertices, &numedges);
        for(int j = 1; j <= numedges; j++){
            scanf("%d %d %d", &auxiliar.a, &auxiliar.b, &auxiliar.weight);
            auxiliar.flag = 0;
            edgelist.push_back(auxiliar);
        }
        sort(edgelist.begin(), edgelist.end(), compare);
        //roda o primeiro kruskal para pegar a melhor MST 
        for(int j = 0; j < (int)edgelist.size(); j++){
            if(find(edgelist[j].a, edgelist[j].b) == false){
                man.push_back(edgelist[j]);
                weighted_union(edgelist[j].a, edgelist[j].b);
                firstmst += edgelist[j].weight;
            }
        }
        //massa agora vamos ter q fazer a boa pra achar as outras msts;
        for(int j = 0; j < (int)man.size(); j++){
            int nc = numvertices;
            price = 0;
            initialize();
            for(int k = 0; k < (int)edgelist.size(); k++){
                if(man[j].a == edgelist[k].a && man[j].b == edgelist[k].b && man[j].weight == edgelist[k].weight){
                    continue;
                }else{
                    if(find(edgelist[k].a, edgelist[k].b) == false){
                        weighted_union(edgelist[k].a, edgelist[k].b);
                        nc--;
                        price += edgelist[k].weight;
                    }
                }
            }
            if(price < secondmst){
                if(nc == 1){
                    secondmst = price;
                }
            }
        }
        printf("%d %d\n", firstmst, secondmst);
    }
    return 0;
}

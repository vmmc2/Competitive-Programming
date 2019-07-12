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
    int flag;
    int numcasos;
    int numvertices, numedges;
    edge auxiliar;
    int mstcost;
    int price;
    scanf("%d", &numcasos);
    for(int a = 1; a <= numcasos; a++){
        flag = 0;
        vector<edge> edgelist;
        vector<edge> marcados;
        initialize();
        scanf("%d %d", &numvertices, &numedges);
        for(int i = 0; i < numedges; i++){
            scanf("%d %d %d", &auxiliar.a, &auxiliar.b, &auxiliar.weight);
            edgelist.push_back(auxiliar);
        }
        sort(edgelist.begin(), edgelist.end(), compare);
        //tentando descobrir a primeira MST 
        int nc = numvertices;
        for(int i = 0; i < (int)edgelist.size(); i++){
            if(find(edgelist[i].a, edgelist[i].b) == false){
                edgelist[i].flag = 1;
                marcados.push_back(edgelist[i]);
                weighted_union(edgelist[i].a, edgelist[i].b);
                nc--;
            }
        }
        /*for(int i = 0; i < (int)edgelist.size(); i++){
            printf("%d %d %d --- flag: %d\n", edgelist[i].a, edgelist[i].b, edgelist[i].weight, edgelist[i].flag);
        }*/
        if(nc != 1){
            printf("Case #%d : No way\n", a);
            continue;
        }
        mstcost = 99999999;
        //parte 2: verificar se da pra montar uma segunda mst 
        for(int i = 0; i < (int)marcados.size(); i++){
            initialize();
            price = 0;
            int numc = numvertices;
            for(int j = 0; j < (int)edgelist.size(); j++){
                //tipo, a seguir eu to marcando as arestas que eu ja usei, para que eu possa rodar o algoritmo
                //capaz de identificar a existencia de uma segunda MST. TEM QUE SE LIGAR SE PODEM EXISTIR MULTIPLAS
                //ARESTAS LIGANDO O MESMO PAR DE VERTICES. NESSE CASO, USE UMA FLAG NA STRUCT EDGE PARA FACILITAR.
                if(marcados[i].a == edgelist[j].a && marcados[i].b == edgelist[j].b && marcados[i].weight == edgelist[j].weight && edgelist[j].flag == 1){
                    continue;
                }else{
                    if(find(edgelist[j].a, edgelist[j].b) == false){
                        weighted_union(edgelist[j].a, edgelist[j].b);
                        numc--;
                        price += edgelist[j].weight;
                    }
                }
            }
            if(price < mstcost){
                if(numc == 1){
                    mstcost = price;
                    flag = 1;
                }
            }
        }
        if(flag == 0){
            printf("Case #%d : No second way\n", a);
        }else{
            printf("Case #%d : %d\n", a, mstcost);
        }
    }
    return 0;
}

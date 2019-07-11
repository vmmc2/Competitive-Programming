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
  long long weight;
};

long long dist(int xa, int ya, int xb, int yb){
    long long deltax = abs(xa - xb);
    long long deltay = abs(ya - yb);
    long long newdx = deltax * deltax;
    long long newdy = deltay * deltay;
    long long answer = newdx + newdy;
    return answer;
}

bool compare(edge xesque, edge dele){
    return xesque.weight < dele.weight;
}

int main(){
    int numcasos;
    int numcomponents;
    int x, y;
    scanf("%d", &numcasos);
    for(int a = 1; a <= numcasos; a++){
        initialize();
        vector<pair<int,int>>pontos;
        vector<edge> finale;
        scanf("%d", &numcomponents);
        while(scanf("%d", &x) == 1 && x != - 1){
            scanf("%d", &y);
            pontos.push_back({x,y});
        }
        //beleza ja to com o vector de pontos suave
        vector<edge>edgelist;
        edge auxiliar;
        for(int i = 0; i < (int)pontos.size() - 1; i++){
            for(int j = i + 1; j < (int)pontos.size(); j++){
                auxiliar.a = i;
                auxiliar.b = j;
                auxiliar.weight = dist(pontos[i].first, pontos[i].second, pontos[j].first, pontos[j].second);
                edgelist.push_back(auxiliar);
            }
        }
        sort(edgelist.begin(), edgelist.end(), compare);
        int numc = (int)pontos.size();
        for(int i = 0; i < (int)edgelist.size(); i++){
            if(find(edgelist[i].a, edgelist[i].b) == false){
                weighted_union(edgelist[i].a, edgelist[i].b);
                numc--;
                if(numc <= numcomponents){
                    printf("%.0lf\n", ceil(sqrt(edgelist[i].weight)));
                    break;
                }
            }
        }
    }
    return 0;
}

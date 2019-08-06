#include <bits/stdc++.h>
#include <cmath>
#define pb push_back

using namespace std;

struct elephant{
    int weight, qi;  
    int index;
};

bool compare(elephant a, elephant b){
    if(a.weight != b.weight){
        return a.weight < b.weight;
    }
    if(a.weight == b.weight){
        return a.qi > b.qi;
    }
    else return false;
}

int main(){
    int peso, iq;
    vector<elephant> registro;
    int sentinela = 0;
    while(scanf("%d %d", &peso, &iq) == 2){
        registro.pb({peso, iq, sentinela});
        sentinela++;
    }
    stable_sort(registro.begin(), registro.end(), compare);
    int n = (int)registro.size();
    int lis[n];
    int pred[n];
    for(int i = 0; i < n; i++){
        lis[i] = 1;
        pred[i] = i;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i - 1; j++){
            if(registro[i].weight > registro[j].weight && registro[i].qi < registro[j].qi){
                if(lis[j] + 1 > lis[i]){
                    lis[i] = lis[j] + 1;
                    pred[i] = j;
                }
            }
        }
    }
    //pegando o maior valor de lis
    int answer = - 2;
    int indicepartida;
    for(int i = 0; i < n; i++){
        if(lis[i] > answer){
            answer = lis[i];
            indicepartida = i;
        }
    }
    vector<int>porra;
    int a;
    printf("%d\n", answer);
    for(a = indicepartida; a != pred[a]; a = pred[a]){
        porra.push_back(registro[a].index);
    }
    porra.push_back(registro[a].index);
    reverse(porra.begin(), porra.end());
    for(int i = 0; i < (int)porra.size(); i++){
        printf("%d\n", porra[i] + 1);
        //if(i != (int)porra.size() - 1) printf("\n");
    }
    return 0;
}

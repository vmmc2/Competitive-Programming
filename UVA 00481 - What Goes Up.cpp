#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#include <iostream>
#define pb push_back
#define pii pair<int,int>
#define INF 999999

using namespace std;

typedef long long ll;

vector<ll>sequence;
vector<pair<ll,int>> lis;

int binary_search(ll x){
    int low = 0;
    int high = (int)lis.size() - 1;
    int index = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(lis[mid].first == x){
            return mid;
        }
        if(lis[mid].first > x){
            high = mid - 1;
        }
        if(lis[mid].first < x){
            index = mid;
            low = mid + 1;
        }
    }
    return index;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll aux;
    while(cin >> aux){
        sequence.pb(aux);
    }
    int n = (int)sequence.size();
    int predecessor[n];
    for(int i = 0; i < n; i++){
        predecessor[i] = i;
    }
    //printf("%d\n", (int)lis.size());
    for(int i = 0; i < n; i++){
        if(lis.size() == 0){
            //printf("entrei!");
            lis.pb({sequence[i],i});
        }else if(sequence[i] > lis[(int)lis.size() - 1].first){
            lis.pb({sequence[i], i});
            int ultimo_elemento = (int)lis.size() - 1;
            predecessor[i] = lis[ultimo_elemento - 1].second;
            //printf("predecessor[%d] = %d\n", i, predecessor[i]);
        }else{
            int position = binary_search(sequence[i]);
            if(position == -1){
                lis[0].first = sequence[i];
                lis[0].second = i;
                predecessor[i] = i;
            }
            else{
                if(lis[position].first != sequence[i]){
                    lis[position + 1].first = sequence[i];
                    lis[position + 1].second = i;
                    predecessor[i] = lis[position].second;
                    //printf("predecessor[%d] = %d\n", i, predecessor[i]);
                }else{
                    lis[position].first = sequence[i];
                    lis[position].second = i;
                    predecessor[i] = lis[position - 1].second;
                    //printf("predecessor[%d] = %d\n", i, predecessor[i]);
                }
            }
        }
    }
    //printf("%d\n", (int)lis.size());
    /*for(int i = 0; i < (int)lis.size(); i++){
        printf("{%ld, %d}\n", lis[i].first, lis[i].second);
    }*/
    /*printf("\n\n");
    for(int i = 0; i < n; i++){
        printf("predecessor[%d] = %d\n", i, predecessor[i]);
    }*/
    //a posicao que o numero eh inserido no LIS indica que ele apresenta a maior lis...
    int tam = (int)lis.size() - 1;
    ll numero_que_devo_procurar = lis[tam].first;
    int s;
    for(int i = n - 1; i >= 0; i--){
        if(sequence[i] == numero_que_devo_procurar){
            s = i;
            break;
        }
    }
    int a;
    vector<ll> finale;
    for(a = s; a != predecessor[a]; a = predecessor[a]){
        finale.pb(sequence[a]);
    }
    finale.pb(sequence[a]);
    reverse(finale.begin(), finale.end());
    printf("%d\n", (int)lis.size());
    printf("-\n");
    for(int i = 0; i < (int)finale.size(); i++){
        printf("%lld\n", finale[i]);
    }
    return 0;
}

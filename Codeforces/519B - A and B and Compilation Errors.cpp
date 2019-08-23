#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 9999999

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    map<int,int> dict1;
    map<int,int> dict2;
    map<int,int> dict3;
    vector<int> registro;
    vector<int> registro2;
    int n, aux;
    int first, second;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> aux;
        registro.pb(aux);
        dict1[aux]++;
    }
    for(int i = 0; i < n - 1; i++){
        cin >> aux;
        dict2[aux]++;
        registro2.pb(aux);
    }
    for(int i = 0; i < n - 2; i++){
        cin >> aux;
        dict3[aux]++;
    }
    //buscando pelo primeiro erro
    for(int i = 0; i < n; i++){
        if(dict1[registro[i]] != dict2[registro[i]]){
            first = registro[i];
            break;
        }
    }
    for(int i = 0; i < n - 1; i++){
        if(dict2[registro2[i]] != dict3[registro2[i]]){
            second = registro2[i];
            break;
        }
    }
    printf("%d\n%d\n", first, second);
    return 0;
}

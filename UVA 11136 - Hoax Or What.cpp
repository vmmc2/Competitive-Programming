
#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctype.h>

using namespace std;


int main(){
    multiset <int> collection;
    multiset <int>:: iterator it;
    int maior;
    int menor;
    long long resposta;
    int numdays;
    int numbills;
    int aux;
    while(scanf("%d", &numdays)){
        if(numdays == 0){
            break;
        }
        resposta = 0;
        for(int i = 1; i <= numdays; i++){
            scanf("%d", &numbills);
            for(int j = 1; j <= numbills; j++){
                scanf("%d", &aux);
                collection.insert(aux);
            }
            menor = *collection.begin();
            it = collection.begin();
            collection.erase(it);
            maior = *collection.rbegin();
            it = collection.end();
            it--;
            collection.erase(it);
            resposta += (maior - menor);
        }
        printf("%lld\n", resposta);
        collection.clear();
    }
    return 0;
}



#include <bits/stdc++.h>

using namespace std;

int main(){
    int numcasos;
    int calls, aux, aux2;
    vector <int> telephone;
    int costmile, costjuice;
    scanf("%d", &numcasos);
    for(int i = 1; i <= numcasos; i++){
        costmile = 0;
        costjuice = 0;
        scanf("%d", &calls);
        for(int j = 0; j < calls; j++){
            cin >> aux;
            telephone.push_back(aux);
        }
        for(int j = 0; j < calls; j++){
            //plano Mile  
            aux2 = ceil(telephone[j]/30)+1;
            costmile += (10*aux2);
            //plano Juice 
            aux2 = ceil(telephone[j]/60)+1;
            costjuice += (15*aux2);
        }
        if(costmile < costjuice){
            printf("Case %d: Mile %d\n", i, costmile);
        }
        else if(costmile > costjuice){
            printf("Case %d: Juice %d\n", i, costjuice);
        }
        else if(costmile == costjuice){
            printf("Case %d: Mile Juice %d\n", i, costmile);
        }
        telephone.clear();
    }
    return 0;
}

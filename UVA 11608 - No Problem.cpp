#include <bits/stdc++.h>
#include <string.h>
#include <math.h>

using namespace std;

int main(){
    vector <int> disponiveis;
    vector <int> required;
    int numproblemsinicio;
    int aux, total;
    int iowa = 1;
    scanf("%d", &numproblemsinicio);
    while(numproblemsinicio >= 0){
        total = numproblemsinicio;
        for(int i = 1; i <= 12; i++){
            scanf("%d", &aux);
            disponiveis.push_back(aux);
        }    
        for(int i = 1; i <= 12; i++){
            scanf("%d", &aux);
            required.push_back(aux);
        }
        printf("Case %d:\n", iowa);
        for(int i = 0; i < 12; i++){
            total -= required[i];
            if(total < 0){
                printf("No problem. :(\n");
                total += required[i];
            }
            else{
                printf("No problem! :D\n");
            }
            //printf("Total: %d\n", total);
            total += disponiveis[i];
            //printf("Total dps: %d\n", total);
        }
        //fim do caso de teste
        disponiveis.clear();
        required.clear();
        iowa++;
        scanf("%d", &numproblemsinicio); 
    }
    return 0;
}

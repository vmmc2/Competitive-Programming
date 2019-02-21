#include <bits/stdc++.h>

using namespace std;

vector <int> da[25];
vector <int> dh[25];
vector <int> dr[25];

void preprocess(){
    for(int i = 0; i < 25; i++){
        da[i].clear();
        dh[i].clear();
        dr[i].clear();
    }
}

int main(){
    int misera;
    int hotels, restaurants, agencies; // 0-based index
    int pa[25], ph[25], pr[25];
    int aux, soma;
    while(scanf("%d %d %d", &agencies, &restaurants, &hotels) == 3){
        misera = -1;
        int ind1, ind2, ind3;
        preprocess();
        soma = (int) 1e8;
        memset(pa, 0, sizeof pa);
        memset(ph, 0, sizeof ph);
        memset(pr, 0, sizeof pr);
        for(int i = 0; i < agencies; i++){
            scanf("%d", &pa[i]);
            for(int j = 0; j < restaurants; j++){
                scanf("%d", &aux);
                da[i].push_back(aux);
            }
        }
        for(int i = 0; i < restaurants; i++){
            scanf("%d", &pr[i]);
            for(int j = 0; j < hotels; j++){
                scanf("%d", &aux);
                dr[i].push_back(aux);
            }
        }
        for(int i = 0; i < hotels; i++){
            scanf("%d", &ph[i]);
            for(int j = 0; j < agencies; j++){
                scanf("%d", &aux);
                dh[i].push_back(aux);
            }
        }
        //fim da leitura de dados
        for(int i = 0; i < agencies; i++){
            for(int j = 0; j < restaurants; j++){
                if(da[i][j] != 1){
                    for(int k = 0; k < hotels; k++){
                        if(dr[j][k] == 0 && dh[k][i] == 0){
                            if(pa[i] + pr[j] + ph[k] < soma){
                                soma = pa[i] + pr[j] + ph[k];
                                misera = 1;
                                ind1 = i;
                                ind2 = j;
                                ind3 = k;
                            }
                        }
                    }
                }
            }
        }
        if(misera == -1){
            printf("Don't get married!\n");
        }
        else{
            printf("%d %d %d: %d\n", ind1, ind2, ind3, soma);
        }
    }
    return 0;
}

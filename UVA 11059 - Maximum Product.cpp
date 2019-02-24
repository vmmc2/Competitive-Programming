#include <bits/stdc++.h>

using namespace std;

int main(){
    int qtdnums;
    int aux, iowa;
    long long answer = 0;
    long long temp = 1;
    int caso = 1;
    vector <int> registro;
    while(scanf("%d", &qtdnums) != EOF){
        answer = 0;
        for(int i = 0; i < qtdnums; i++){
            scanf("%d", &aux);
            registro.push_back(aux);
        }
        for(int i = 0; i < (int)registro.size(); ++i, temp = 1){
            for(int j = i; j < (int)registro.size(); ++j){
                temp = temp * registro[j];
                if(temp > answer){
                    answer = temp;
                }
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", caso, answer);
        registro.clear();
        caso++;
    }
    return 0;
}

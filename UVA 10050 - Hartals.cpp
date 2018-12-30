#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main(){
    int numcasos;
    int numdias, numpp, aux;
    int answer;
    int k, j, sentinel;
    vector <int> pp;
    vector <int> days;
    scanf("%d", &numcasos);
    for(int i = 0; i < numcasos; i++){//Realizando cada caso de teste.
        answer = 0;
        scanf("%d", &numdias);
        days.assign(numdias, 0);//Dando um "malloc" no vector
        scanf("%d", &numpp);
        for(j = 1; j <= numpp; j++){
            scanf("%d", &aux);
            aux--;
            pp.push_back(aux);
        }
        //preprocess: friday e saturday
        for(j = 5; j < numdias; j = j+7){
            if(j < numdias-1){
                days[j] = 69;
                days[j+1] = 69;
            }
            if(j == numdias-1){
                days[j] = 69;
            }
        }
        //end of preprocessing
        for(j = 0; j < numpp; j++){
            sentinel = pp[j];
            int dale = sentinel+1;
            for(k = sentinel; k < numdias; k = k + dale){
                if(days[k] == 0){
                    days[k] = 1;
                }
            }
        }
        for(j = 0; j < numdias; j++){
            //printf("%d ", days[j]);
            if(days[j] == 1){
                answer++;
            }
        }
        printf("%d\n", answer);
        pp.clear();
        days.clear();
    }
    return 0;
}

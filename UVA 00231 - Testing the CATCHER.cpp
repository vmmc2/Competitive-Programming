#include <bits/stdc++.h>
#include <cmath>
#define pb push_back

using namespace std;

int main(){
    int aux;
    int caso = 1;
    int flag = 0;
    while(true){
        vector<int> misseis;
        int answer = -999999;
        scanf("%d", &aux);
        if(aux == -1){
            break;
        }
        if(flag++){
            printf("\n");
        }
        while(true){
            misseis.pb(aux);
            scanf("%d", &aux);
            if(aux == -1){
                break;
            }
        }
        int n = (int)misseis.size();
        int lis[n];
        for(int i = 0; i < n; i++){
            lis[i] = 1;
        }
        lis[0] = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= i - 1; j++){
                if(misseis[i] <= misseis[j]){
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }
        for(int i = 0; i < n; i++){
            answer = max(answer, lis[i]);
        }
        printf("Test #%d:\n", caso);
        printf("  maximum possible interceptions: %d\n", answer);
        caso++;
    }
    return 0;
}

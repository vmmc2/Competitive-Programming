#include <bits/stdc++.h>
#include <cmath>
#define pb push_back

using namespace std;

int main(){
    int num;
    while(true){
        scanf("%d", &num);
        if(num == 0){
            break;
        }
        vector <int> gambles;
        int aux;
        int answer = 0, sum = 0;
        for(int i = 0; i < num; i++){
            scanf("%d", &aux);
            gambles.pb(aux);
        }
        for(int i = 0; i < num; i++){
            sum += gambles[i];
            if(sum < 0){
                sum = 0 ;
            }
            if(sum > answer){
                answer = sum;
            }
        }
        if(answer == 0){
            printf("Losing streak.\n");
        }else{
            printf("The maximum winning streak is %d.\n", answer);
        }
    }
    return 0;
}

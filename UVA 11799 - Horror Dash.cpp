#include <bits/stdc++.h>

using namespace std;

int main(){
    int numcasos, i = 1;
    int students, maior = -23;
    int speed;
    scanf("%d", &numcasos);
    while(numcasos--){
        maior = -23;
        scanf("%d", &students);
        for(int j = 1; j <= students; j++){
            scanf("%d", &speed);
            if(speed > maior){
                maior = speed;
            }
        }
        printf("Case %d: %d\n", i, maior);
        i++;
    }
    return 0;
}

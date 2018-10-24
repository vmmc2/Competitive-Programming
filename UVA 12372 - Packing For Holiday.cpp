#include <bits/stdc++.h>

using namespace std;

int main(){
    int numcasos, i = 1;
    int length, width, heigth;
    scanf("%d", &numcasos);
    while(numcasos--){
        scanf("%d %d %d", &length, &width, &heigth);
        if(length <= 20 && width <= 20 && heigth <= 20){
            printf("Case %d: good\n", i);
        }
        else{
            printf("Case %d: bad\n", i);
        }
    i++;
    }
    return 0;
}

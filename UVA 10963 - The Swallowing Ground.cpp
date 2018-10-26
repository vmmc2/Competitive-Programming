#include <bits/stdc++.h>

using namespace std;

int main(){
    int numcasos, numcol;
    int north, south;
    int diff, actual;
    int i;
    bool sera;
    scanf("%d", &numcasos);
    while(numcasos--){
        sera = true;
        scanf("%d", &numcol);
        scanf("%d %d", &north, &south);
        actual = abs(north - south);
        for(i = 0; i < numcol-1; i++){
            scanf("%d %d", &north, &south);
            diff = abs(north-south);
            if(diff != actual){
                sera = false;
            }
        }
        if(sera == true){
            printf("yes\n");
        }
        else if(sera == false){
            printf("no\n");
        }
        if(numcasos){
            printf("\n");
        }
    }
    return 0;
}

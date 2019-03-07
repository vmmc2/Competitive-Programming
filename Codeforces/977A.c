#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int n;
    int numop;
    int i;
    scanf("%d %d", &n, &numop);
    for(i = 1; i <=numop; i++){
        if(n%10 == 0){
            n = n/10;
        }
        else{
            n = n - 1;
        }
    }
    printf("%d\n", n);

    return 0;
}

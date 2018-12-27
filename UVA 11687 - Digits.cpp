#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main(){
    char str[3000000];
    int sum;
    int aux;
    int ok;
    while(1){
        scanf(" %s", str);
        aux = 0;
        ok = 0;
        if(str[0] == 'E'){
            break;
        }
        if(strcmp(str,"1") == 0){
            printf("1\n");
            continue;
        }
        while(1){
            aux++;
            int num = strlen(str);
            if(num == 1){
                break;
            }
            sprintf(str,"%d",num);
        }    
        printf("%d\n", aux+1);
    }
    return 0;
}

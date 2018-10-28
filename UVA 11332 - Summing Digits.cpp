#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main(){
    char str[3000000];
    int sum;
    while(1){
        scanf(" %s", str);
        if(strcmp(str,"0") == 0){
            break;
        }
        sum = 0;
        while(strlen(str) != 1){
            for(int i = 0; i < strlen(str); i++){
                sum += str[i] - 48;
            }
            sprintf(str,"%d",sum);
        sum = 0;    
        }    
        printf("%s\n", str);
    }
    return 0;
}

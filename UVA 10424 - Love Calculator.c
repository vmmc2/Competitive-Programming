#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int random(char str[]){
    int number, sum;
    int i;
    while(strlen(str) != 1){
            for(i = 0; i < strlen(str); i++){
                sum += str[i] - 48;
            }
            sprintf(str,"%d",sum);
        sum = 0;    
        }
    number = str[0]-48;  
    return number;
}

int main(){
    int number1, number2;
    char nome1[600], nome2[600];
    char aux1[50], aux2[50];
    int answer1, answer2;
    double final1, final2;
    int i;
    while(gets(nome1)){
        gets(nome2);
        number1 = 0, number2 = 0;
        for(i = 0; i < strlen(nome1); i++){
            nome1[i] = tolower(nome1[i]);
        }
        for(i = 0; i < strlen(nome2); i++){
            nome2[i] = tolower(nome2[i]);
        }
        for(i = 0; i < strlen(nome1); i++){
            if((int)nome1[i] >= 97 && (int)nome1[i] <= 122){
                number1 += (nome1[i]-96);
            }    
        }
        sprintf(aux1, "%d", number1);
        answer1 = random(aux1);
        for(i = 0; i < strlen(nome2); i++){
            if((int)nome2[i] >= 97 && (int)nome2[i] <= 122){
                number2 += (nome2[i]-96);
            }
        }
        sprintf(aux2, "%d", number2);
        answer2 = random(aux2);
        final1 = (double) answer1/answer2;
        final2 = (double) answer2/answer1;
        if(final1 > 1.0000000){
            final2 = final2*100;
            printf("%.2lf %\n", final2);
        }
        else if(final2 > 1.000000){
            final1 = final1*100;
            printf("%.2lf %\n", final1);
        }
        else if(final1 == final2){
            final1 = final1*100;
            printf("%.2lf %\n", final1);
        }
    }
    return 0;
}

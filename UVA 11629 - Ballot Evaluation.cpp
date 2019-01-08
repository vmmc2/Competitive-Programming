#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(){
    map <string,double> dictionary;
    int numpalavras;
    double total;
    int guesses;
    string aux;
    char expression[100000];
    char dale[10000];
    int num2;
    int num;
    int a, b;
    cin >> numpalavras >> guesses;
    for(int i = 1; i <= numpalavras; i++){
        scanf("%s %d.%d", dale, &a, &b);
        dictionary[dale] = a*10+b;
    }
    getchar();
    for(int i = 1; i <= guesses; i++){
        gets(expression);
        stringstream line(expression);
        printf("Guess #%d: ", i);
        total = 0;
        while(line >> expression){
            if(strcmp(expression,"+") == 0){
                continue;
            }
            if(strcmp(expression,"=") == 0){
                line >> num;
                if(total == num*10){
                  printf("was correct.\n");
                }
                else{
                  printf("was incorrect.\n");
                }
                break;
            }
            if(strcmp(expression,"<") == 0){
                line >> num;
                if(total < num*10){
                  printf("was correct.\n");
                }
                else{
                  printf("was incorrect.\n");
                }
                break;
            }
            if(strcmp(expression,">") == 0){
                line >> num;
                if(total > num*10){
                  printf("was correct.\n");
                }
                else{
                  printf("was incorrect.\n");
                }
                break;
            }
            if(strcmp(expression,">=") == 0){
                line >> num;
                if(total >= num*10){
                  printf("was correct.\n");
                }
                else{
                  printf("was incorrect.\n");
                }
                break;
            }
            if(strcmp(expression,"<=") == 0){
                line >> num;
                if(total <= num*10){
                  printf("was correct.\n");
                }
                else{
                  printf("was incorrect.\n");
                }
                break;
            }
            total += dictionary[expression];
        }
    }
    return 0;
}

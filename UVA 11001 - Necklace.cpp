#include <bits/stdc++.h>
#include <math.h>
#include <sstream>
#include <string.h>

using namespace std;

int main(){
    char s1[200];
    char s2[200];
    int vtotal, vzero;
    int begin, cont;
    double dale;
    double diameter;
    double iowa;
    double len;
    double answer;
    int p;
    while(scanf("%d %d", &vtotal, &vzero) == 2){
        if(vtotal == 0 && vzero == 0){
            break;
        }
        answer = 0;
        for(int i = 1; i <= vtotal; i++){
            dale = (double) vtotal/i;
            if(dale - vzero > 0){
                diameter = 0.3*sqrt(dale-vzero)*i;
            }
            else{
                break;
            }
            sprintf(s1,"%.10lf", diameter);
            sprintf(s2,"%.10lf", answer);
            if(strcmp(s1,s2) == 0){
                p = 0;
                break;
            }
            else if(diameter > answer){
                answer = diameter;
                p = i;
            }
            else if(diameter < answer){
                break;
            }
        }
        printf("%d\n", p);
    }
    return 0;
}

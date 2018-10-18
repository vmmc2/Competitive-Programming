#include <bits/stdc++.h>

using namespace std;

int main(){
   int numcasos, numero, answer;
   scanf("%d", &numcasos);
   while(numcasos--){
       scanf("%d", &numero);
       answer = numero*567;
       answer = answer/9;
       answer = answer + 7492;
       answer = answer * 235;
       answer = answer/47;
       answer = answer - 498;
       answer = answer/10;
       answer = answer%10;
       printf("%d\n", abs(answer));
   }
   return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
   int numcasos, i = 1;
   int vetor[3];
   scanf("%d", &numcasos);
   while(numcasos--){
       scanf("%d %d %d", &vetor[0], &vetor[1], &vetor[2]);
       sort(vetor,vetor+3);
       printf("Case %d: %d\n", i, vetor[1]);
       i++;
   }
   return 0;
}

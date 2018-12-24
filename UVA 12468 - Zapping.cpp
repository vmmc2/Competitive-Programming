#include <bits/stdc++.h>

using namespace std;
int min(int x, int y){
    if(x > y){
        return y;
    }
    else{
        return x;
    }
}
int max(int x, int y){
    if(x > y){
        return x;
    }
    else{
        return y;
    }
}

int main(){
    int a, b;
    int opcao1, opcao2;
    int menor, maior;
    scanf("%d %d", &a, &b);
    while(a != -1 && b != -1){
        opcao1 = abs(a-b);
        menor = min(a,b);
        maior = max(a,b);
        opcao2 = (menor-0)+(99-maior)+1;
        int answer = min(opcao1, opcao2);
        printf("%d\n", answer);
        scanf("%d %d", &a, &b);
    }
    return 0;
}

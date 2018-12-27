#include <bits/stdc++.h>

using namespace std;

int main(){
    int flag;//Se for 1 quer dizer que deu merda.
    string registro;
    int a, b;
    int inicio, fim;
    int numqueries;
    int caso = 1;
    while(cin>>registro){
        flag = 0;
        scanf("%d", &numqueries);
        printf("Case %d:\n", caso);
        for(int i = 0; i < numqueries; i++){
            flag = 0;
            scanf("%d %d", &a, &b);
            inicio = min(a,b);
            fim = max(a,b);
            for(int j = inicio; j <= fim-1; j++){
                if(registro[j] != registro[j+1]){
                    flag = 1;
                }
            }
            if(flag == 1){
                printf("No\n");
            }
            else{
                printf("Yes\n");
            }
        }
        caso++;
    }
    return 0;
}

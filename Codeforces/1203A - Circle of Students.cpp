#include <bits/stdc++.h>
#include <cmath>
#define pb push_back
#define INF 999999
#define pii pair<int,int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numcasos;
    cin >> numcasos;
    for(int a = 1; a <= numcasos; a++){
        int n;
        cin >> n;
        if(n == 1){
            cout << "YES" << endl;
            continue;
        }
        vector<int> lugares (n);
        int sentinela;
        for(int i = 0; i < n; i++){
            cin >> lugares[i];
            if(lugares[i] == 1) sentinela = i;
        }
        //rodando para a direita: clockwise...
        int start = sentinela;
        int flag = 1;
        //printf("%d\n", start);
        while(start <= n - 2){ //checo ate o penultimo elemento do array... checo o penultimo e o ultimo.
            if(lugares[start + 1] - lugares[start] != 1){
                //printf("entrei 1 -- %d --- %d\n", lugares[start], lugares[start + 1]);
                flag = 0;
            }
            start++;
        }
        //checa agora o ultimo com o primeiro...
        if(sentinela != 0){
            if(lugares[0] - lugares[n - 1] != 1){
                flag = 0;
                //printf("entrei 2\n");
            }
        }
        start = 0;
        ///printf("%d\n", sentinela - 1);
        while(start <= sentinela - 2){
            if(lugares[start + 1] - lugares[start] != 1){
                //printf("entrei 3 --- %d --- %d\n", lugares[start], lugares[start + 1]);
                flag = 0;
            }
            start++;
        }
        //printf("flag: %d\n", flag);
        if(flag == 0){
        flag = 1;
        //rodando para a esquerda: anti-clockwise
        start = sentinela;
        //printf("start: %d\n", start);
        while(start >= 1){
            //printf("dale");
            if(lugares[start - 1] - lugares[start] != 1){
                flag = 0;
            }
            start--;
        }
        if(sentinela != n - 1){
            if(lugares[n - 1] - lugares[0] != 1){
                //printf("ok");
                flag = 0;
            }
        }
        start = n - 1;
        while(start >= sentinela + 2){
            if(lugares[start - 1] - lugares[start] != 1){
                //printf("deu ruim");
                flag = 0;
            }
            start--;
        }
        }
        if(flag == 1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

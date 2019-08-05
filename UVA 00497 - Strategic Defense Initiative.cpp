#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 999999

using namespace std;

int main(){
    //FAST INPUT/OUTPUT
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    
    int b;
    int numcasos;
    cin >> numcasos;
    cin.ignore();
    cin.ignore();
    for(int a = 1; a <= numcasos; a++){
        vector<int> misseis;
        string lixeira;
        
        while(getline(cin, lixeira) && lixeira != ""){
            stringstream ss(lixeira);
            int missil;
            
            ss >> missil;
            misseis.pb(missil);
        }
        int n = (int)misseis.size();
        int lis[n];
        int predecessor[n];
        for(int i = 0; i < n; i++){
            lis[i] = 1;
            predecessor[i] = i;
        }
        //montando agora o lis 
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i - 1; j++){
                if(misseis[i] > misseis[j]){
                    //printf("i: %d --- lis[i]: %d ----- lis[j] + 1: %d --- j: %d\n", i, lis[i], lis[j] + 1, j);
                    if(lis[j] + 1 > lis[i]){
                        lis[i] = lis[j] + 1;
                        predecessor[i] = j;
                    }
                }
            }
        }
        vector<int> answer;
        int maximo = 0;
        int indicepartida;
        for(int i = 0; i < n; i++){
            if(maximo < lis[i]){
                maximo = lis[i];
                indicepartida = i;
            }
        }
        /*for(int i = 0; i < n; i++){
            printf("%d ", predecessor[i]);
        }
        printf("\n");*/
        for(b = indicepartida; b != predecessor[b]; b = predecessor[b]){
            //printf("jogando missel: %d\n", misseis[b]);
            answer.push_back(misseis[b]);
        }
        //printf("\n");
        answer.push_back(misseis[b]);
        reverse(answer.begin(), answer.end());
        printf("Max hits: %d\n", maximo);
        for(int i = 0; i < (int)answer.size(); i++){
            printf("%d\n", answer[i]);
        }
        if(a < numcasos){
            printf("\n");
        }
    }
    return 0;
}

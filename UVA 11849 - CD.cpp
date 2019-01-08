#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i;
    int maior = -1;
    int cont;
    int aux;
    int N, M; //N para jack e M para jill
    map<int ,int >cd;
    cin>>N>>M;
    while(N!=0 && M!=0){
        maior = -1;
        cont = 0;
        for(i = 1; i <=N; i++){
            cin>>aux;
            if(aux > maior){
                maior = aux;
            }
            cd[aux]++;
        }
        for(i = 1; i <=M; i++){
            cin>>aux;
            if(aux > maior){
                maior = aux;
            }
            cd[aux]++;
        }
        for(i = 0; i<= maior; i++){
            if(cd[i] >=2){
                cont++;
            }
        }
        cout<<cont<<"\n";
        cd.clear();
        cin>>N>>M;
    }
    return 0;
}

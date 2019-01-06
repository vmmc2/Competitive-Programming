#include <bits/stdc++.h>

using namespace std;

int main(){
    int numcasos;
    map <string,int> dictionary;
    int D;
    string aux;
    int aux2;
    int subjects;
    string homework;
    scanf("%d", &numcasos);
    for(int i = 1; i <= numcasos; i++){
        scanf("%d", &subjects);
        for(int j = 1; j <= subjects; j++){
            cin >> aux >> aux2;
            dictionary[aux] = aux2;
        }
        cin >> D;
        cin >> homework;
        if(dictionary.find(homework) == dictionary.end()){
            printf("Case %d: Do your own homework!", i);
        }
        else if(dictionary[homework] > D+5){
            printf("Case %d: Do your own homework!", i);
        }
        else if(dictionary[homework] <= D){
            printf("Case %d: Yesss", i);
        }
        else if(dictionary[homework] > D && dictionary[homework] <= D+5){
            printf("Case %d: Late", i);
        }
        printf("\n");
        dictionary.clear();
    }
    return 0;
}

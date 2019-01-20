#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#include <string.h>
#include <iomanip>

using namespace std;

int main(){
    int numcasos;
    int numcasas;
    int aux;
    int mediana, answer;
    vector <int> houses;
    vector <int>:: iterator it;
    scanf("%d", &numcasos);
    for(int i = 1; i <= numcasos; i++){
        scanf("%d", &numcasas);
        for(int j = 1; j <= numcasas; j++){
            scanf("%d", &aux);
            houses.push_back(aux);
        }
        stable_sort(houses.begin(), houses.end());
        answer = 0;
        mediana = houses[(int)houses.size()/2];
        for(int j = 0; j < houses.size(); j++){
            if(mediana == houses[j]){
                continue;
            }
            answer += abs(mediana - houses[j]);
        }
        printf("%d\n", answer);
        houses.clear();
    }
    return 0;
}

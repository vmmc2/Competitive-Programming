#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#include <string.h>
#include <iomanip>

using namespace std;

int main(){
    vector <int> front;
    vector <int> rear;
    vector <double> ratio;
    int frontspr, rearspr;
    int aux;
    double dale, answer, iowa;
    while(scanf("%d %d", &frontspr, &rearspr) == 2){
        for(int i = 1; i <= frontspr; i++){
            scanf("%d", &aux);
            front.push_back(aux);
        }
        for(int i = 1; i <= rearspr; i++){
            scanf("%d", &aux);
            rear.push_back(aux);
        }
        for(int i = 0; i < (int) rear.size(); i++){
            for(int j = 0; j < (int) front.size(); j++){
                dale = (double) rear[i]/front[j];
                ratio.push_back(dale);
            }
        }
        answer = 0.00;
        stable_sort(ratio.begin(), ratio.end());
        for(int i = 0; i <= ratio.size()-2; i++){
            iowa = ratio[i+1]/ratio[i];
            if(iowa > answer){
                answer = iowa;
            }
        }
        printf("%.2lf\n", answer);
        ratio.clear();
        front.clear();
        rear.clear();
    }
    return 0;
}

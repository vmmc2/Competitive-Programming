#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#include <iostream>
#define INF 9999999
#define pb push_back
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    int vetor[10] = {0}; //vetor que representa o status do hotel inicialmente
    string events = "";
    cin >> n;
    cin >> events;
    for(int i = 0 ; i < (int)events.length(); i++){
        if(events[i] == 'L'){
            for(int i = 0; i <= 9; i++){
                if(vetor[i] == 0){
                    vetor[i] = 1;
                    break;
                }
            }
        }
        if(events[i] == 'R'){
            for(int i = 9; i >= 0; i--){
                if(vetor[i] == 0){
                    vetor[i] = 1;
                    break; 
                }
            }
        }
        if(events[i] == '0') vetor[0] = 0;
        if(events[i] == '1') vetor[1] = 0;
        if(events[i] == '2') vetor[2] = 0;
        if(events[i] == '3') vetor[3] = 0;
        if(events[i] == '4') vetor[4] = 0;
        if(events[i] == '5') vetor[5] = 0;
        if(events[i] == '6') vetor[6] = 0;
        if(events[i] == '7') vetor[7] = 0;
        if(events[i] == '8') vetor[8] = 0;
        if(events[i] == '9') vetor[9] = 0;
    }
    for(int i = 0; i <= 9; i++){
        printf("%d", vetor[i]);
    }
    return 0;
    
}

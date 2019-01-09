#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctype.h>

using namespace std;

struct argus{
    int ID, tempo, v;
};

struct compare{
    bool operator()(argus a, argus b){
        if(a.v != b.v)
            return a.v > b.v;
        return a.ID > b.ID;
    }
};

int main(){
    priority_queue <argus, vector<argus>, compare> heap;
    char str[100];
    int id, tempo1;
    argus temporary;
    int numiteracoes;
    while(scanf(" %s", str) == 1){
        if(str[0] == '#'){
            break;
        }
        scanf("%d %d", &id, &tempo1);
        temporary.ID = id;
        temporary.tempo = tempo1;
        temporary.v = tempo1;
        heap.push(temporary);
    }
    scanf("%d", &numiteracoes);
    for(int i = 1; i <= numiteracoes; i++){
        temporary = heap.top();
        heap.pop();
        printf("%d\n", temporary.ID);
        temporary.v += temporary.tempo;
        heap.push(temporary);
    }
    return 0;
}

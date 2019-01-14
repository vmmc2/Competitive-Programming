#include <bits/stdc++.h>
#include <sstream>

using namespace std;

vector <int> adjlist[1010];
void readData(int node, string dale){
    stringstream ss;
    int number;
    ss << dale;
    while(ss >> number){
        adjlist[node].push_back(number);
    }    
}

int main(){
    vector <int> resposta;
    int numcasos;
    int vertices;
    int aux;
    int minN;
    string halo;
    scanf("%d", &numcasos);
    for(int i = 1; i <= numcasos; i++){
        scanf("%d", &vertices);
        getline(cin, halo);
        for(int j = 1; j <= vertices; j++){
            getline(cin, halo);
            readData(j, halo);
        }
        getline(cin, halo);
        minN = 10000000;
        for(int j = 1; j <= vertices; j++){
            minN = min(minN, (int) adjlist[j].size());
        }
        for(int j = 1; j <= vertices; j++){
            if(adjlist[j].size() == minN){
                resposta.push_back(j);
            }
        }
        for(int j = 0; j < (int)resposta.size(); j++){
            if(j < (int)resposta.size()-1){
                printf("%d ", resposta[j]);
            }
            else{
                printf("%d\n", resposta[j]);
            }
        }
        resposta.clear();
        for(int j = 0; j < 1010; j++){
            adjlist[j].clear();
        }
    }
    return 0;
}

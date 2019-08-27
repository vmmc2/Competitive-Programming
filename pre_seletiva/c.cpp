#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#include <string.h>
#define pb push_back
#define INF 99999999

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct player{
    string nome;
    int points;
};

bool compare(player a1, player a2){
    if(a1.points != a2.points){
        return a1.points > a2.points;
    }else{
        return a1.nome < a2.nome;
    }
}

int main(){
    int numplayers;
    int caso = 1;
    while(scanf("%d", &numplayers) == 1){
        vector<player> registro;
        for(int i = 0; i < numplayers; i++){
            int pontos = 0;
            string name;
            string lixeira
            getline(cin, lixeira);
            stringstream ss;
            //int v[25];
            //char nome[100];
            //scanf("%[^\n]s ;%d %d %d %d %d;%d %d %d %d %d;%d %d %d %d %d;%d %d %d %d %d;%d %d %d %d %d",nome, &v[0], &v[1], &v[2], &v[3], &v[4], &v[5], &v[6], &v[7], &v[8], &v[9], &v[10], &v[11], &v[12], &v[13], &v[14], &v[15], &v[16], &v[17], &v[18], &v[19], &v[20], &v[21], &v[22], &v[23], &v[24]);
            //printf("%s\n", nome);
            for(int i = 0; i < 25; i++){
                if(i == 4 || i == 9 || i == 14 || i == 19 || i == 24){
                    pontos += (2*v[i]);
                }else{
                    pontos += v[i];
                }
            }
            for(int i = 0; i < strlen(nome); i++){
                if(nome[i] >= 65 && nome[i] <= 90){
                    name += (char)(nome[i] + 32);
                }else{
                    name += nome[i];
                }
            }
            player aux;
            aux.nome = name;
            aux.points = pontos;
            registro.pb(aux);
        }
        sort(registro.begin(), registro.end(), compare);
        //printf("Case %d:\n", caso);
        /* for(int i = 0; i < (int)registro.size(); i++){
            cout << registro[i].nome << " " << registro[i].points << "\n";
        }*/
        caso++;
    }
    return 0;
}

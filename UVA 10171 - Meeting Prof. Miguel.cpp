#include <bits/stdc++.h>
#include <cmath>
#define pb push_back

using namespace std;

int main(){
    int numedges;
    char c, d;
    char age, direction, x, y;
    int weight;
    char me, miguel;
    char alpha, omega;
    while(scanf("%d", &numedges) == 1 && numedges != 0){
        int graph1[26][26], graph2[26][26];
        map<char,int>dicionary;
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                graph1[i][j] = 100000000;
                graph2[i][j] = 100000000;
            }
            graph1[i][i] = 0;
            graph2[i][i] = 0;
        }
        for(int i = 1; i <= numedges; i++){
            cin >> age >> direction >> c >> d >> weight;
            x = c - 'A';
            y = d - 'A';
            if(age == 'Y'){
                if(direction == 'U'){
                    graph1[x][y] = min(graph1[x][y], weight);
                }else{
                    graph1[x][y] = graph1[y][x] = min(graph1[x][y], weight);
                }
                
            }else if(age == 'M'){
                if(direction == 'U'){
                    graph2[x][y] = min(graph2[x][y], weight);
                }else{
                    graph2[x][y] = graph2[y][x] = min(graph2[x][y], weight);
                }
            }
        }
        //roda floyd-warshall
        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    graph1[i][j] = min(graph1[i][j], graph1[i][k] + graph1[k][j]);
                    graph2[i][j] = min(graph2[i][j], graph2[i][k] + graph2[k][j]);
                }
            }
        }
        cin >> alpha >> omega;
        me = alpha - 'A';
        miguel = omega - 'A';
        int answer = 100000000;
        for(int i = 0; i < 26; i++){
            if(graph1[me][i] + graph2[miguel][i] < answer){
                answer = graph1[me][i] + graph2[miguel][i];
            }
        }
        if(answer == 100000000){
            printf("You will never meet.\n");
        }
        else{
            printf("%d", answer);
            for(int i = 0; i < 26; i++){
                if(graph1[me][i] + graph2[miguel][i] == answer){
                    printf(" %c", i + 'A');
                }
            }
            puts("");
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define mp make_pair
#define INF 99999999

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll adjmat[12][12];
int p[12][12];

void init(){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            adjmat[i][j] = INF;
            p[i][j] = i;
        }
    }
    return;
}

void floyd_warshall(int numvertex){
    for(int k = 1; k <= numvertex; k++){
        for(int i = 1; i <= numvertex; i++){
            for(int j = 1; j <= numvertex; j++){
                if(adjmat[i][k] + adjmat[k][j] < adjmat[i][j]){
                    adjmat[i][j] = adjmat[i][k] + adjmat[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }
    return;
}

void printPath(int i, int j){
    if(i != j){
        printPath(i, p[i][j]);
    }
    cout << " " << j;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int numvertex;
    int caso = 1;
    while(true){
        cin >> numvertex;
        if(numvertex == 0) break;
        init();
        int neigh;
        int to, weight;
        for(int i = 1; i <= numvertex; i++){
            cin >> neigh;
            for(int j = 0; j < neigh; j++){
                cin >> to >> weight;
                adjmat[i][to] = weight;
            }
        }
        int source, dest;
        cin >> source >> dest;
        floyd_warshall(numvertex);
        cout << "Case " << caso << ": Path =";
        printPath(source, dest);
        cout << "; ";
        cout << adjmat[source][dest] << " second delay\n";
        caso++;
    }
    return 0;
}

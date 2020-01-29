#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define mp make_pair
#define INF 99999999

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull adjmat[120][120];
ull adjmat2[120][120];

void init(){
    for(int i = 0; i < 120; i++){
        for(int j = 0; j < 120; j++){
            adjmat[i][j] = (1 << 30);
            adjmat2[i][j] = (1 << 30);
        }
    }
    return;
}

void floyd_warshall(int numvertices){
    for(int k = 1; k <= numvertices; k++)
        for(int i = 1; i <= numvertices; i++)
            for(int j = 1; j <= numvertices; j++)
                adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j]);
    return;
}

void floyd_warshall2(int numvertices){
    for(int k = 1; k <= numvertices; k++)
        for(int i = 1; i <= numvertices; i++)
            for(int j = 1; j <= numvertices; j++)
                adjmat2[i][j] = min(adjmat2[i][j], adjmat2[i][k] + adjmat2[k][j]);
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numvertices;
    while(cin >> numvertices){ //vertices estao enumerados de 1, 2, 3, ..., n.
        init();
        cin.ignore();
        if(numvertices == 0) break;
        string lixeira;
        for(int i = 1; i <= numvertices; i++){
            getline(cin, lixeira);
            stringstream ss(lixeira);
            int source, dest;
            ss >> source;
            while(ss >> dest){
                adjmat[source][dest] = 1;
            }
        }
        floyd_warshall(numvertices);
        for(int i = 1; i <= numvertices; i++){
            getline(cin, lixeira);
            stringstream ss(lixeira);
            int source, dest;
            ss >> source;
            while(ss >> dest){
                adjmat2[source][dest] = 1;
            }
        }
        floyd_warshall2(numvertices);
        int A, B;
        cin >> A >> B;
        bool deubom = true;
        for(int i = 1; i <= numvertices; i++){
            for(int j = 1; j <= numvertices; j++){
                if(i == j || adjmat[i][j] == (1 << 30)) continue;
                if(adjmat2[i][j] > (A*adjmat[i][j]) + B){
                    deubom = false;
                }
            }
        }
        if(deubom){
            cout << "Yes" << "\n";
        }else{
            cout << "No" << "\n";
        }
    }
    return 0;
}

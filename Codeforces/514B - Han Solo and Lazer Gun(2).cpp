#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 9999999
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int troopers, xhan, yhan;
    cin >> troopers >> xhan >> yhan;
    map<double,int> dicio; //map que para cada coeficiente angular, eu guardo a quantidade de stormtroopers que podem ser acertados naquela angulacao..
    int xstorm, ystorm;
    int infinito = 0;
    for(int i = 0; i < troopers; i++){
        cin >> xstorm >> ystorm;
        int deltax = xstorm - xhan;
        int deltay = ystorm - yhan;
        //printf("dy: %d ------ dx: %d\n", deltay, deltax);
        if(deltax == 0){
            infinito = 1;
            //cout << "inf" << endl;
            continue;
        }
        double coeficiente = (double)deltay/deltax;
        //cout << coeficiente << endl;
        dicio[coeficiente]++;
    }
    int answer = infinito + (int)dicio.size();
    printf("%d\n", answer);
    return 0;
}

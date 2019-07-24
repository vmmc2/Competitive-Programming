#include <bits/stdc++.h>
#include <cmath>
#define pb push_back
 
using namespace std;
 
int main(){
    //FAST I/O
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int dormitorios, numcartas;
    unsigned long long aux;
    unsigned long long doom;
    unsigned long long dorm;
    
    vector<unsigned long long> cartas;
    vector<unsigned long long> soma;
    vector<unsigned long long> rooms;
    
    rooms.pb(0);
    cartas.pb(0);
    soma.pb(0);
    
    cin >> dormitorios >> numcartas;
    //cout << dormitorios << " "  << numcartas << endl;
    for(int i = 1; i <= dormitorios; i++){
        cin >> aux;
        rooms.pb(aux);
    }
    for(int i = 1; i <= numcartas; i++){
        cin >> aux;
        cartas.pb(aux);
    }
    for(int i = 1; i <= dormitorios; i++){
        aux = soma[i - 1] + rooms[i];
        soma.pb(aux);
    }
    for(int i = 1; i <= numcartas; i++){
        //BINARY SEARCH
        int start = 1;
        int end = dormitorios;
        int result = -1;
        int mid;
        while(start <= end){
            mid = (start + end)/2;
            if(cartas[i] <= soma[mid]){
                result = mid;
                end = mid - 1;
            }
            else if(cartas[i] > soma[mid]){
                start = mid + 1;
            }
        }
        doom =  cartas[i] - soma[result - 1];
        cout << result << " " << doom << endl;
    }
    return 0;
}

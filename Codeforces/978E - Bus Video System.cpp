#include <bits/stdc++.h>
#include <cmath>
#define pb push_back

using namespace std;

int main(){
    //Fast I/O 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numstops, capacity;
    int aux;
    int b = 0;
    int maxb = -300000, minb = 10000000;
    long int lf, rg;
    vector<int> bus;
    
    cin >> numstops >> capacity;
    
    for(int i = 0; i < numstops; i++){
        cin >> aux;
        bus.pb(aux);
    }
    for(int i = 0; i < (int)bus.size(); i++){
        b += bus[i];
        maxb = max(b, maxb);
        minb = min(b, minb);
    }
    if(maxb > capacity){
        cout << "0" << endl;
        return 0;
    }
    //vendo o minimo de passageiros
    if(minb < 0){
        lf = abs(minb);
    }else{
        lf = 0;
    }
    //vendo o maximo de passageiros
    if(maxb <= 0){
        rg = capacity;
    }else{
        rg = capacity - maxb;
    }
    //compara
    if(lf > rg){
        cout << "0" << endl;
    }else{
        cout << rg - lf + 1 << endl;
    }
    
    
    return 0;
}

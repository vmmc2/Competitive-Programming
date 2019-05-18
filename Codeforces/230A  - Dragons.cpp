#include <bits/stdc++.h>

using namespace std;

struct drag{
    int power;
    int bonus;
};

bool compara(drag viserion, drag drogon){
    return viserion.power < drogon.power;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    drag aux;
    int perdeu = 0;
    int kirito, numdragons;
    vector<drag> dracarys;
    cin >> kirito >> numdragons;
    for(int i = 1; i <= numdragons; i++){
        cin >> aux.power >> aux.bonus;
        dracarys.push_back(aux);
    }
    sort(dracarys.begin(), dracarys.end(), compara);
    for(int i = 0; i < (int)dracarys.size(); i++){
        if(kirito > dracarys[i].power){
            kirito += dracarys[i].bonus;
        }else{
            perdeu = 1;
            break;
        }
    }
    if(perdeu == 1){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
    return 0;
}

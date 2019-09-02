#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 9999999

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

void solve(ll m, ll x){
    ll ganho;
    if(x == 100){//se a porcentagem de retirada for total...
        cout << "Not found" << endl; //sem solucao
        return;
    }
    ganho = (m - 1)*100/(100 - x);
    ll aux1, aux2;
    aux1 = (m - 1)*100;
    aux2 = (100 - x);
    if(aux1%aux2 == 0){
        ganho--;
    }
    if(ganho >= m){
        cout << ganho << endl;
    }else{
        cout << "Not found" << endl;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(true){
        ll m, x;
        cin >> m >> x;
        if(m == 0 && x == 0){
            break;
        }else{
            solve(m, x);
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 99999999
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, k;
    ll id;
    queue <ll> fila;
    unordered_map<ll,int> tanafila;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> id;
        if(tanafila[id] == 0){//se o cara nao ta na fila
            if(fila.size() < k){//se da pra por cara na fila eh so dar o push
                fila.push(id);
            }else{ //se a fila ja ta cheia, tem que retirar o ultimo cara da fila e marcar que ele nao está mais presente na fila
                ll aux = fila.front();
                fila.pop();
                tanafila[aux] = 0;
                fila.push(id);
            }
            tanafila[id] = 1;
        }
        //cout << (int)fila.size() << "\n";
    }
    cout << (int)fila.size() << "\n";
    vector<ll> answer;
    while(!fila.empty()){ //tem que ver como funciona essa parte de insercao e de remover um elemento de uma queue 
        ll aux = fila.front();
        fila.pop();
        answer.pb(aux);
    }
    reverse(answer.begin(), answer.end());
    for(int i = 0; i < (int)answer.size(); i++){
        cout << answer[i] << " ";
    }
    return 0;
}

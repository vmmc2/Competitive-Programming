#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <sstream>
#include <cmath>
#define INF 99999999
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<int, null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numcasos;
    cin >> numcasos;
    for(int a = 1; a <= numcasos; a++){
        multiset<ll> registro;
        int m, n;
        ll aux;
        cin >> m >> n;
        vector<ll> numbers;
        vector<ll>sequence;
        for(int i = 0; i < m; i++){
            cin >> aux;
            numbers.pb(aux);
        }
        registro.insert(numbers[0]);
        int sz = 1;
        bool first = true;
        int u;
        int indice = 0;
        multiset<ll>::iterator it = registro.begin();
        for(int i = 0; i < n; i++){
            cin >> u;
            while(u > sz){
                registro.insert(numbers[sz]);
                if(numbers[sz] < *it){
                    it--;
                }
                sz++;
            }
            if(first){
                it = registro.begin();
                first = false;
            }else{
                it++;
            }
            cout << *it << "\n";
        }
        if(a != numcasos) cout << "\n";
    }
    return 0;
}

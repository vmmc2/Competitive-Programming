#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 9999999

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int m, b;
    cin >> m >> b;
    
    ll x = b * m;
    ll answer = -10;
    for(ll i = 0; i <= x; i++){
        if(i%m != 0) continue;
        else{
            ll y = -i/m + b;
            //limite do x = i;
            //limite do y = y;
            //somando os valores de y dado um y limite...
            ll somay = (ll)((1 + y)*y)/2;
            ll somaytotal = somay * (i - 0 + 1);
            //somando os valores de x dado um y limite...
            ll somax = (ll)((1 + i)*i)/2;
            ll somaxtotal = somax * (y - 0 + 1);
            //printf("i: %d ----- somaxtotal: %lld ----- somaytotal: %lld\n", i, somaxtotal, somaytotal);
            ll somafinal = somaxtotal + somaytotal;
            answer = max(answer, somafinal);
        }
    }
    cout << answer << endl;
    return 0;
}

#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 9999999

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numcasos;
    cin >> numcasos;
    for(int i = 1; i <= numcasos; i++){
        ll k;
        cin >> k;
        if(k < 0){
            k = abs(k);
        }
        ll n = 1;
        while(true){
            ll soma_pa = (n*(n + 1))/2;
            if(soma_pa >= k && (soma_pa - k)%2 == 0){
                break;
            }
            n += 1;
        }
        printf("%lld\n", n);
        if(i != numcasos) printf("\n");
    }
    return 0;
}

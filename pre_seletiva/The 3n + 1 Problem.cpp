#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#define pb push_back
#define INF 9999999
#define MOD 998244353

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int i, j;
    int i1, j1;
    ll cycle;
    while(scanf("%d %d", &i, &j) == 2){
        cycle = -1;
        i1 = i;
        j1 = j;
        if(i > j){
            swap(i, j);
        }
        for(int a = i; a <= j; a++){
            int inicio = a;
            int now = 1;
            while(inicio != 1){
                if(inicio%2 != 0) inicio = (3*inicio) + 1;
                else inicio = inicio/2;
                now++;
            }
            if(now > cycle) cycle = now;
        }
        printf("%d %d %lld\n", i1, j1, cycle);
    }
    return 0;
}

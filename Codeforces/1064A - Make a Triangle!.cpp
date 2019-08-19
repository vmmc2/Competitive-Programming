#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 999999

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a , b, c;
    
    cin >> a >> b >> c;
    if((a < b + c) && (b < a + c) && (c < a + b)){
        printf("0\n");
        return 0;
    }
    else{
        vector<int> lados(3);
        lados[0] = a;
        lados[1] = b;
        lados[2] = c;
        sort(lados.begin(), lados.end());
        int soma_desejada = lados[2] + 1;
        int answer = soma_desejada - (lados[0] + lados[1]);
        cout << answer << "\n";
    }
    
    return 0;
}

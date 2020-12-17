#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dl;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll a, b, x, y;
    ll answer = 0;
    cin >> x >> y >> a >> b;

    //Ate qual iteracao eh mais vantajoso eu ir pelo a*x ao inves do x + b
    while((double)a*x <= 2e18 && a*x <= x + b && a*x < y){
        x = x*a;
        answer++;
    }
    answer += (y - x - 1)/b; //Esse '-1' eh pq lembre-se que o pet nao deve chegar no 'y' de fato.
    cout << answer << endl;


    return 0;
}

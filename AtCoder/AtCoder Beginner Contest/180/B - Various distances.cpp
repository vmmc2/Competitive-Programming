#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll manhattan = 0, chebyshev;
    ld euclidian = 0.0000000000000;
    cin >> n;
    
    vector<ll> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    //Manhattan
    for(int i = 0; i < n; i++){
        manhattan += abs(v[i]);
    }
    //Chebyshev
    chebyshev = abs(v[0]);
    for(int i = 1; i < n; i++){
        chebyshev = max(chebyshev, abs(v[i]));
    }
    //Euclidean
    for(int i = 0; i < n; i++){
        long double aux = (long double) v[i];
        aux = aux*aux;
        euclidian += aux;
    }
    //cout << euclidian << endl;
    euclidian = sqrt((long double)euclidian);

    cout << manhattan << endl;
    cout << setprecision(17) << euclidian << endl;
    cout << chebyshev << endl;

    return 0;
}

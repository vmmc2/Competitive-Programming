#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int minimum = 201;
    int maximum = -201;
    vector<int> v(n);
    
    for(int i = 0; i < n; i++){
        cin >> v[i];
        minimum = min(minimum, v[i]);
        maximum = max(maximum, v[i]);
    }
    
    if(minimum == maximum){ //Todos os numeros do vetor sao iguais.
        cout << "0" << endl;
        return 0;
    }
    
    int left = minimum;
    int right = maximum;
    ll answer = 1e8;
    for(int a = minimum; a <= maximum; a++){
        ll cost = 0;
        for(int i = 0; i < n; i++){
            cost += ((v[i] - a)*(v[i] - a));
        }
        //cout << "Cost: " << cost << "\n";
        //cout << "Derived: " << derived << "\n\n";
        answer = min(answer, cost);
    }
    
    cout << answer << "\n";
    
    
    
    return 0;
}

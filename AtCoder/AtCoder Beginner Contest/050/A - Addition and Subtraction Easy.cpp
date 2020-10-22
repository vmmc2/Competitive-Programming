#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll a, b;
    char c;
    
    cin >> a >> c >> b;
    
    if(c == '+'){
        cout << a + b << endl;
    }else if(c == '-'){
        cout << a - b << endl;
    }
    
    
    return 0;
}

#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    ll a, b, x, y, n;
    cin >> t;
 
    for(int z = 0; z < t; z++){
        cin >> a >> b >> x >> y >> n;
        ll ogA = a;
        ll ogB = b;
        ll ogN = n;
        //O lance eh focar diminuir do numero maior primeiro. oq sobrar, tirar do menor.
        // primeiro calculo...
        ll diffA = abs(x - a);
        ll diffB = abs(y - b);
        ll ans1, ans2;
        if(n >= diffA){ 
            a -= diffA;
            n -= diffA;
            if(n >= diffB){
                b -= diffB;
                n -= diffB;
            }else{
                b -= n;
            }
            ans1 = a * b;
            //cout << "a1: " << a << " --- b1: " << b << "\n";
        }else{
            a -= n;
            ans1 = a * b;
            //cout << "a1: " << a << " --- b1: " << b << "\n";
        }
        a = ogA, b = ogB, n = ogN;
        diffA = abs(x - a);
        diffB = abs(y - b);
        if(n >= diffB){
            b -= diffB;
            n -= diffB;
            if(n >= diffA){
                a -= diffA;
                n -= diffA;
            }else{  
                a -= n;
            }
            ans2 = a * b;
            //cout << "a2: " << a << " --- b2: " << b << "\n";
        }else{
            b -= n;
            ans2 = a * b;
            //cout << "a2: " << a << " --- b2: " << b << "\n";
        }
        cout << min(ans1, ans2) << "\n";
    }
 
    return 0;
}

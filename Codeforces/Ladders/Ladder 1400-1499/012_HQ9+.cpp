#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string program;
    cin >> program;

    for(auto x : program){
        if(x == 'H' || x == 'Q' || x == '9'){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;


    return 0;
}

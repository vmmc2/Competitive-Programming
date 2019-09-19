#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define INF 9999999
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string frase;
    cin >> frase;
    stack<char> s;
    int count = 0;
    for(int i = 0; i < (int)frase.length(); i++){
        if(s.empty()) s.push(frase[i]);
        else{
            if(s.top() == frase[i]){
                s.pop();
                count++;
            }else{
                s.push(frase[i]);
            }
        }
    }
    if(count % 2 == 1) cout << "Yes" << "\n";
    else{
        cout << "No" << "\n";
    }
    return 0;
}

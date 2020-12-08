#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    string s;

    cin >> n >> x;
    cin >> s;

    for(auto c : s){
        if(c == 'o') x++;
        else{
            if(x > 0) x--;
        }
    }

    cout << x << endl;

    return 0;
}

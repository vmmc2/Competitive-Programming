#include <bits/stdc++.h>
#include <sstream>

using namespace std;

string to_lower_case(string s){
    for(int i = 0; i < (int)s.size(); i++){
        if((int)s[i] >= 65 && (int)s[i] <= 90){
            s[i] = (char)((int)s[i] + 32);
        }
    }
    return s;
}

int main(){
    string a, b;
    cin >> a;
    cin >> b;

    a = to_lower_case(a);
    b = to_lower_case(b);

    if(a < b){
        cout << -1 << endl;
    }else if(a == b){
        cout << 0 << endl;
    }else{
        cout << 1 << endl;
    }

    return 0;
}

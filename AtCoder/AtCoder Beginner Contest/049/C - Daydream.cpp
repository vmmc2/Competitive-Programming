#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    
    int tam = (int)s.size();
    
    
    int i = 0;
    while(i < tam){
        if(tam - i < 5){
            cout << "NO" << endl;
            return 0;
        }
        if(s.substr(i, 5) == "maerd"){
            i += 5;
        }else if(s.substr(i, 7) == "remaerd"){
            i += 7;
        }else if(s.substr(i, 5) == "esare"){
            i += 5;
        }else if(s.substr(i, 6) == "resare"){
            i += 6;
        }else{
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    
    
    return 0;
}

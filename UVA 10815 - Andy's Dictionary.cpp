#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#define INF 99999999
#define pb push_back

using namespace std;

bool valido(char c){
    return c >= 'a' && c <= 'z';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string aux;
    int nova;
    set<string> registro;
    while(cin >> aux){
        int n = (int)aux.size();
        string lixeira = "";
        for(int i = 0; i < n; i++){
            char c = tolower(aux[i]);
            if(valido(c)){
                lixeira += c;
            }else if(lixeira != ""){
                registro.insert(lixeira);
                lixeira = "";
            }
        }
        if(lixeira != ""){
            registro.insert(lixeira);
        }
    }
    for(set<string>::iterator it = registro.begin(); it != registro.end(); it++){
        cout << *it << "\n";
    }
    return 0;
}

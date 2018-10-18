#include <bits/stdc++.h>

using namespace std;

int main(){
    int i = 1;
    string aux;
    map <string,string> dictionary;
    dictionary["HELLO"] = "ENGLISH";
    dictionary["HOLA"] = "SPANISH";
    dictionary["HALLO"] = "GERMAN";
    dictionary["BONJOUR"] = "FRENCH";
    dictionary["CIAO"] = "ITALIAN";
    dictionary["ZDRAVSTVUJTE"] = "RUSSIAN";
    while(getline(cin,aux)){
        if(aux == "#"){
            break;
        }
        if(dictionary.find(aux) != dictionary.end()){
            cout << "Case " << i << ": " << dictionary[aux] << endl;
        }
        else{
            cout << "Case " << i << ": UNKNOWN" << endl;
        }
        i++;
    }

    return 0;
}

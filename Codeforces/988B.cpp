#include <bits/stdc++.h>

using namespace std;

int custom(string a, string b){
    return a.size() < b.size();
}

int main(){
    vector <string> dicionario;
    string auxiliar;
    int qtdstrings, i, j;
    int flag;
    cin >> qtdstrings;
    for(i = 1; i <= qtdstrings; i++){
        cin >> auxiliar;
        dicionario.push_back(auxiliar);
    }
    sort(dicionario.begin(), dicionario.end(), custom);
    for(i = 0; i < dicionario.size() - 1; i++){
        for(j = i+1; j < dicionario.size(); j++){
            if(dicionario[j].find(dicionario[i]) == std::string::npos){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    for(i = 0; i < dicionario.size(); i++){
        cout << dicionario[i] << endl;
    }

    return 0;
}

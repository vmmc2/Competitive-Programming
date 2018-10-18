#include <bits/stdc++.h>

using namespace std;

int main(){
    string auxiliar;
    string um = "one";
    string dois = "two";
    int error = 0;
    int cases;
    scanf("%d", &cases);
    while(cases--){
        error = 0;
        cin >> auxiliar;
        if(auxiliar == "one"){
            cout << "1" << endl;
            continue;
        }
        else if(auxiliar == "two"){
            cout << "2" << endl;
            continue;
        }
        else if(auxiliar == "three"){
            cout << "3" << endl;
            continue;
        }
        int tam = auxiliar.length();
        if(tam == 3){
            for(int i = 0; i < tam; i++){
                if(auxiliar[i] != um[i]){
                    error++;
                }
            }
            if(error == 1){
                cout << "1" << endl;
            }
            else{
                cout << "2" << endl;
            }
        }
        else if(tam == 5){
            cout << "3" << endl;
        }

    }
    return 0;
}

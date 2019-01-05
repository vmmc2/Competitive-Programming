#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main(){
    vector<string> final;
    int numcards;
    string s1, s2;
    string aux;
    string aux2;
    int dale, iowa;
    int tam, j;
    scanf("%d", &numcards);
    while(numcards != 0){
        final.assign(numcards, "0");
        iowa = 0;
        for(int i = 0; i < numcards; i++){
            cin >> s1 >> aux2;
            tam = aux2.length();
            while(tam){
                if(final[iowa] == "0"){
                    tam--;
                }
                iowa++;
                if(iowa >= numcards){
                    iowa = 0;
                }
            }
            final[(iowa - 1 + numcards)%numcards] = s1;
        }
        for(int i = 0; i < numcards; i++){
            if(i != numcards-1){
                cout << final[i] << " ";
            }
            else{
                cout << final[i];
            }
        }
        cout << endl;
        scanf("%d", &numcards);
    }
    return 0;
}

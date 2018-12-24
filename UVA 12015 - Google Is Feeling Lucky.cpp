#include <bits/stdc++.h>

using namespace std;

int main(){
    int numcasos;
    string aux;
    int numaux;
    int max = -99999;
    vector <pair<string,int>> dictionary;
    scanf("%d", &numcasos);
    for(int i = 1; i <= numcasos; i++){
        max = -99999;
        for(int j = 0; j < 10; j++){
            cin >> aux >> numaux;
            dictionary.push_back(make_pair(aux,numaux));
        }
        for(int j = 0; j < 10; j++){
            if(dictionary[j].second > max){
                max = dictionary[j].second;
            }
        }
        printf("Case #%d:\n", i);
        for(int j = 0; j < 10; j++){
            if(dictionary[j].second == max){
                cout << dictionary[j].first << endl;
            }
        }
        dictionary.clear();
    }
    return 0;
}

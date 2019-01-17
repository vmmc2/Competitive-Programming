#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int main(){
    map <string, pair<int,int>> dictionary;
    vector <string> answer;
    int numcasos;
    int price;
    int numcarros;
    int low, high;
    string nome;
    scanf("%d", &numcasos);
    for(int i = 1; i <= numcasos; i++){
        scanf("%d", &numcarros);
        for(int j = 1; j <= numcarros; j++){
            cin >> nome >> low >> high;
            if(dictionary.find(nome) == dictionary.end()){
                dictionary[nome] = {low,high};
            }
            else{
                if(low < dictionary[nome].first){
                    dictionary[nome].first = low;
                }
                if(high > dictionary[nome].second){
                    dictionary[nome].second = high;
                }
            }
        }
        scanf("%d", &numcarros);
        for(int j = 1; j <= numcarros; j++){
            scanf("%d", &price);
            for(map<string, pair<int,int>>:: iterator it = dictionary.begin(); it != dictionary.end(); it++){
                //printf("price %d ---- low: %d --- high: %d\n", price, it->second.first, it->second.second);
                if(price >= it->second.first && price <= it->second.second){
                    answer.push_back(it->first);
                }
            }
            //printf("answer size is %d\n", (int)answer.size());
            if((int)answer.size() == 1){
                cout << answer[0] << endl;
            }
            else{
                cout << "UNDETERMINED" << endl;
            }
            answer.clear();
        }
        dictionary.clear();
        if(i < numcasos) printf("\n");
    }
    return 0;
}

#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int main(){
    int registro[9];
    vector<pair<int,string>> answer;
    int bcg = 0, bgc = 0, cbg = 0, cgb = 0, gbc = 0, gcb = 0;
    int auxiliar;
    string aux;
    stringstream ss;
    while(cin >> registro[0] >> registro[1] >> registro[2] >> registro[3] >> registro[4] >> registro[5] >> registro[6] >> registro[7] >> registro[8]){
        bcg = registro[3] + registro[6] + registro[2] + registro[8] + registro[1] + registro[4];
        bgc = registro[3] + registro[6] + registro[1] + registro[7] + registro[2] + registro[5];
        cbg = registro[5] + registro[8] + registro[0] + registro[6] + registro[1] + registro[4];
        cgb = registro[5] + registro[8] + registro[1] + registro[7] + registro[0] + registro[3];
        gbc = registro[4] + registro[7] + registro[0] + registro[6] + registro[2] + registro[5];
        gcb = registro[4] + registro[7] + registro[2] + registro[8] + registro[0] + registro[3];
        answer.push_back({bcg,"BCG"});
        answer.push_back({bgc,"BGC"});
        answer.push_back({cbg,"CBG"});
        answer.push_back({cgb,"CGB"});
        answer.push_back({gbc,"GBC"});
        answer.push_back({gcb,"GCB"});
        
        sort(answer.begin(), answer.end());
        cout << answer[0].second << " " << answer[0].first << endl;
        answer.clear();
    }
    return 0;
}

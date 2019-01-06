#include <bits/stdc++.h>

using namespace std;

int main(){
    int numslogans;
    int numqueries;
    map <string,string> dictionary;
    map <string,string>:: iterator it;
    string key;
    string value;
    cin >> numslogans;
    getchar();
    while(numslogans--){
        getline(cin, key);
        getline(cin, value);
        dictionary[key] = value;
    }
    cin >> numqueries;
    getchar();
    for(int i = 1; i <= numqueries; i++){
        getline(cin, key);
        cout << dictionary[key] << endl;
    }
    return 0;
}

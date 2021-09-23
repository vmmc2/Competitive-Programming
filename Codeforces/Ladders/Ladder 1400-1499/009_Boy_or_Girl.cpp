#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string name;
    set<char> counter;

    cin >> name;

    for(auto x : name){
        counter.insert(x);
    }
    if((int)counter.size() % 2 != 0){
        cout << "IGNORE HIM!" << endl;
    }else{
        cout << "CHAT WITH HER!" << endl;
    }


    return 0;
}

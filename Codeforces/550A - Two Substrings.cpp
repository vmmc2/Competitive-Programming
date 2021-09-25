#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    bool hassusbstr = false;
    
    cin >> s;

    for(int i = 0; i < s.size() - 1; i++){
        if((s[i] == 'A' && s[i + 1] =='B') || (s[i] == 'B' && s[i + 1] == 'A')){
            hassusbstr = true;
            break;
        }
    }
    if(hassusbstr == false){
        cout << "NO" << endl;
        return 0;
    }
    vector<int> abpos, bapos;
    for(int i = 0; i < (int)s.size() - 1; i++){
        if(s[i] == 'A' && s[i + 1] =='B'){
            abpos.push_back(i);
        }else if(s[i] == 'B' && s[i + 1] == 'A'){
            bapos.push_back(i);
        }
    }
    if(abpos.size() == 0 || bapos.size() == 0){
        cout << "NO" << endl;
        return 0;
    }
    if(abs(abpos[0] - bapos.back()) >= 2){
        cout << "YES" << endl;
        return 0;
    }
    if(abs(bapos[0] - abpos.back()) >= 2){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;

    return 0;
}

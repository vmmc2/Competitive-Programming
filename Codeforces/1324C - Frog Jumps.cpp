#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numcasos;
    string s;
    
    cin >> numcasos;
    for(int i = 1; i <= numcasos; i++){
        cin >> s;
        vector<int> v;
        v.push_back(0);
        for(int j = 0; j < (int)s.size(); j++){
            if(s[j] == 'R') v.push_back(j + 1);
        }
        v.push_back((int)s.size() + 1);
        int answer = -1;
        for(int j = 0; j < (int)v.size() - 1; j++){
            answer = max(answer, v[j + 1] - v[j]);
        }
        cout << answer << "\n";
    }
    return 0;
}

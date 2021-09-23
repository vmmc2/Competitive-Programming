#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> v(k);
    map<int,bool> segmentTaken;
    vector<vector<int>> answer(k);
    for(int i = 0; i < k; i++){
        cin >> v[i];
    }
    for(int i = 0; i < k; i++){
        answer[i].push_back(v[i]);
        segmentTaken[v[i]] = true;
    }
    int cursor = 0;
    for(int i = 1; i <= n * k; i++){
        if(segmentTaken[i] == false){
            if(answer[cursor].size() < n){
                answer[cursor].push_back(i);
            }else{
                cursor++;
                answer[cursor].push_back(i);
            }
            segmentTaken[i] = true;
        }
    }

    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

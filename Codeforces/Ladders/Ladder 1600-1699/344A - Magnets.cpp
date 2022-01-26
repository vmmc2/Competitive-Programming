#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int main(){
    int n, answer = 1;
    cin >> n;

    if(n == 1){
        cout << 1 << endl;
        return 0;
    }

    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 1; i < n; i++){
        if(v[i] != v[i-1]) answer++;
    }
    cout << answer << endl;

    return 0;
}

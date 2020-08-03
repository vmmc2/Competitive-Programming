#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numcasos;
    cin >> numcasos;
    for(int a = 1; a <= numcasos; a++){
        int n;
        bool found = false;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        for(int i = 0; i < n - 2; i++){
            if(v[i] < v[i + 1] && v[i + 1] > v[i + 2]){
                found = true;
                cout << "YES" << "\n";
                cout << i + 1 << " " << i + 2 << " " << i + 3 << "\n";
                break;
            }
        }
        if(found == false){
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}

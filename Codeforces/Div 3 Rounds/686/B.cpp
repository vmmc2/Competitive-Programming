#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t, n;
    cin >> t;
 
    for(int a = 0; a < t; a++){
        cin >> n;
        vector<int> v(n);
 
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        map<int,int> freq; //mapeia o numero para a frequencia dele.
        map<int,int> index; //mapeia o numero para o index dele.
 
        for(int i = 0; i < n; i++){
            freq[v[i]]++;
            index[v[i]] = i;
        }
        bool found = false;
        int answer = -1;
 
        for(map<int,int>::iterator it = freq.begin(); it != freq.end(); it++){
            if(it->second == 1){
                found = true;
                answer = index[it->first];
                break;
            }
        }
        if(answer != -1) cout << answer + 1 << "\n";
        else cout << answer << "\n";
    }
 
    return 0;
}

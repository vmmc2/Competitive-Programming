#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
bool allEqual(vector<int> &v){
    bool ok = true;
    int pivot = v[0];
    for(int i = 0; i < (int)v.size(); i++){
        if(v[i] != pivot){
            ok = false;
            break;
        }
    }
    return ok;
}
 
bool allDiferent(vector<int> &v){
    map<int,int> freq;
    for(int i = 0; i < (int)v.size(); i++){
        freq[v[i]]++;
    }
    for(map<int,int>::iterator it = freq.begin(); it != freq.end(); it++){
        if(it->second > 1) return false;
    }
    return true;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t, n;
    cin >> t;
 
    for(int a = 0; a < t; a++){
        cin >> n;
        
        vector<int> v(n);
        map<int,vector<int>> indexes;
 
        for(int i = 0; i < n; i++){
            cin >> v[i];
            indexes[v[i]].push_back(i);
        }
        if(allEqual(v) == true){
            cout << "0" << "\n";
        }else if(allDiferent(v) == true){
            cout << "1" << "\n";
        }else{
            int answer = 1e7;
            for(map<int,vector<int>>::iterator it = indexes.begin(); it != indexes.end(); it++){
                vector<int> aux = it->second;
                int current = 0;
                if((int)aux.size() == 1){
                    if(aux[0] == 0 || aux[0] == n - 1){
                        current = 1;
                    }else{
                        current = 2;
                    }
                }else{
                    for(int i = 0; i < (int)aux.size(); i++){
                        if(i == 0){
                            if(aux[i] > 0) current++;
                        }else if(i == (int)aux.size() - 1){
                            if(aux[i] < n - 1) current++;
                            if(aux[i] > aux[i - 1] + 1) current++;
                        }else{
                            if(aux[i] > aux[i - 1] + 1) current++;
                        }
                    }
                }
                answer = min(answer, current);
            }
            cout << answer << "\n";
        }
    }
 
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<int,int> gcdness;
    map<int,int> present;

    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        present[v[i]] = 1;
    }
    sort(v.begin(), v.end());
    int maximo = v[(int)v.size() - 1];
    for(int i = 2; i <= maximo; i++){
        for(int j = 0; j < n; j++){
            if(present[i] == 1) continue;
            if(v[j] % i == 0) gcdness[i]++;
        }
    }

    for(int i = 0; i < n; i++){
        gcdness[v[i]]++;
        for(int j = i + 1; j < n; j++){
            if(v[j] % v[i] == 0) gcdness[v[i]]++;
        }
    }


    int ans = -1;
    int num;
    for(unordered_map<int,int>::iterator it = gcdness.begin(); it != gcdness.end(); it++){
        if(it->second > ans){
            ans = it->second;
            num = it->first;
        }
    }
    cout << num << endl;

    return 0;
}

#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m;
    int answer = 1000;
    cin >> n >> m;
 
    vector<int> v(m);
    for(int i = 0; i < m; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
 
    int left = 0, right = n - 1;
    while(right < (int)v.size()){
        answer = min(answer, v[right] - v[left]);
        left++;
        right++;
    }
 
    cout << answer << endl;
 
    return 0;
}

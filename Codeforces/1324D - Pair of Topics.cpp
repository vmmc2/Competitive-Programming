#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numtopics;
    ll answer = 0;
    cin >> numtopics;
    
    vector<int> a(numtopics);
    vector<int> b(numtopics);
    vector<int> c(numtopics);
    
    for(int i = 0; i < numtopics; i++){
        cin >> a[i];
    }
    for(int i = 0; i < numtopics; i++){
        cin >> b[i];
    }
    for(int i = 0; i < numtopics; i++){
        c[i] = a[i] - b[i];
    }
    sort(c.begin(), c.end());
    for(int i = 0; i < numtopics; i++){
        if(c[i] <= 0) continue;
        int pos = lower_bound(c.begin(), c.end(), -c[i] + 1) - c.begin();
        answer += i - pos;
    }
    
    cout << answer << "\n";
    return 0;
}

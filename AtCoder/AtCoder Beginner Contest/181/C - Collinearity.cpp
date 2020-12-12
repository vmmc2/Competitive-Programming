#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll calcDet(pair<ll,ll> p1, pair<ll,ll> p2, pair<ll,ll> p3){
    ll part1 = p1.first*p2.second + p1.second*p3.first + p2.first*p3.second;
    ll part2 = p2.second*p3.first + p1.first*p3.second + p1.second*p2.first;
    return (part1 - part2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<ll,ll>> points(n);
    bool found = false;
    for(int i = 0; i < n; i++){
        cin >> points[i].first >> points[i].second;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(i != j && i != k && j != k){
                    if(calcDet(points[i], points[j], points[k]) == 0){
                        found = true;
                        goto finish;
                    }
                }
            }
        }
    }
    finish:

    if(found == true) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

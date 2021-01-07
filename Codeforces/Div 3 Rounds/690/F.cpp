#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    int n, l, r;
    cin >> t;

    for(int a = 0; a < t; a++){
        int answer = 1e7;
        cin >> n;
        vector<pair<int,int>> segments;
        vector<int> left;
        vector<int> right;
        for(int i = 0; i < n; i++){
            cin >> l >> r;
            segments.push_back({l, r});
            left.push_back(l);
            right.push_back(r);
        }
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        for(int i = 0; i < n; i++){
            auto seg = segments[i];
            int L = lower_bound(right.begin(), right.end(), seg.first) - right.begin();  //segmentos que terminam antes do segmento atual
            int R = n - (int)(upper_bound(left.begin(), left.end(), seg.second) - left.begin());  //segmentos que comecam dps do atual.. NAO USE v.end(). USE o tamanho do vector.
            //cout << "L: " << L << " --- R: " << R << "\n";
            answer = min(answer, L + R);
        }
        cout << answer << "\n";
    }

    return 0;
}

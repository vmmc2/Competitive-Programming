#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int r1, r2, c1, c2;
    cin >> r1 >> c1;
    cin >> r2 >> c2;

    int answer = 3;

    if(r1 == r2 && c1 == c2){
        answer = 0;
        cout << answer << endl;
    }else{
        if(r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2 || abs(r1 - r2) + abs(c1 - c2) <= 3){
            answer = 1;
            cout << answer << endl;
        }
        else if((r1 + c1 + r2 + c2) % 2 == 0 || abs(r1 - r2) + abs(c1 - c2) <= 6 || abs((r1 + c1) - (r2 + c2)) <= 3 || abs((r1 - c1) - (r2 - c2)) <= 3){
            answer = 2;
            cout << answer << endl;
        }
        else{
            cout << answer << endl;
        }
    }

    return 0;
}

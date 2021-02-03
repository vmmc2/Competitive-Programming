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
    int n, x, y;
    cin >> t;

    for(int z = 0; z < t; z++){
        vector<int> answer;
        cin >> n >> x >> y;
        int ogN = n;
        if(n == 2){
            cout << x << " " << y << "\n";
            continue;
        }

        int lgDiff = y - x;
        int remElements = n - 1;
        int ratio;
        for(int i = remElements; i >= 1; i--){
            cout << (double)lgDiff/(double)remElements << " --- " << (double)(lgDiff/remElements) << "\n";
            if((double)lgDiff/(double)remElements  != (double)(lgDiff/remElements)) continue;
            else{ //Achei.
                cout << "entrei" << "\n";
                ratio = lgDiff/remElements;
                int a1 = 0;
                while(y > 0 && n > 0){
                    y -= ratio;
                    n--;
                }
                y += ratio;
                a1 = y;
                for(int yy = 0; yy < ogN; yy++){
                    answer.push_back(a1);
                    a1 += ratio;
                }
                break;
            }
        }

        for(auto num : answer){
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}

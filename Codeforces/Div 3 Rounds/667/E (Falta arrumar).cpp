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
    cin >> t;

    for(int caso = 0; caso < t; caso++){
        ll n, k;
        cin >> n >> k;
        vector<int> xcoord(n), ycoord(n);
        for(int i = 0; i < n; i++){
            cin >> xcoord[i];
        }
        for(int i = 0; i < n; i++){
            cin >> ycoord[i];
        }
        sort(xcoord.begin(), xcoord.end());
        int curr = 0;
        int counter = 0;
        int fstMax = 0, sndMax = 0;
        ll right = xcoord[0] + k;
        while(curr < n){
            if(xcoord[curr] <= right){
                counter++;
                curr++;
            }else{ //morgou um grupo.
                cout << "curr: " << curr << "\n";
                if(counter >= fstMax && counter >= sndMax){
                    sndMax = fstMax;
                    fstMax = counter;
                }else if(counter < fstMax && counter >= sndMax){
                    sndMax = counter;
                }
                curr--;
                counter = 1;
                right = xcoord[curr] + k;
            }
        }
        if(counter >= fstMax && counter >= sndMax){
            sndMax = fstMax;
            fstMax = counter;
        }else if(counter < fstMax && counter >= sndMax){
            sndMax = counter;
        }
        cout << (fstMax + sndMax) << "\n";

    }


    return 0;
}

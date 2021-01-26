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
    int sum;
    cin >> t;
 
    for(int a = 0; a < t; a++){
       cin >> sum;
       if(sum == 1){
            cout << "0" << "\n";
            continue;
        }
        //Part 1: Computa o sqrt()
        double x1 = sqrt((double)sum);
        int c = (int)floor(x1);
        //Part 2
        double x2 = (double)sum/(double)c;
        int b = (int)floor(x2) - 1;
        if(fabs(floor(x2) - x2) < 1e-9) b--;
        cout << c + b << "\n";
    }
 
    return 0;
}

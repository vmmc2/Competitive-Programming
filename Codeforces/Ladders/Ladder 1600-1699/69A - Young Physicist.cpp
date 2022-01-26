#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int main(){
    int x, y, z;
    int n, sx = 0, sy = 0, sz = 0;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x >> y >> z;
        sx += x;
        sy += y;
        sz += z;
    }

    if(sx == 0 && sy == 0 && sz == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}

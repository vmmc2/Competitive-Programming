#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int getFirstElement(int y, int ratio, int n){
    while((y - ratio) <= 0 || n > 1){
        if(y - ratio <= 0) break;
        y -= ratio;
        n--;
    }
    return y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    int n, x, y;

    cin >> t;
    for(int caso = 0; caso < t; caso++){
        cin >> n >> x >> y;
        if(n == 2){
            cout << x << " " << y << "\n";
            continue;
        }
        int meios = n;
        int firstElement = -1;
        int trueRatio = -1;
        while(meios > 0){
            double ratio = ((double)(y - x))/(double)(meios - 1);
            int ratio2 = (y - x)/(meios - 1);
            if(ratio == (double)ratio2){
                firstElement = getFirstElement(y, ratio, n);
                trueRatio = ratio;
                break;
            }
            meios--;
        }
        for(int i = 0; i < n; i++){
            cout << firstElement << " ";
            firstElement += trueRatio;
        }
        cout << "\n";
    }

    return 0;
}

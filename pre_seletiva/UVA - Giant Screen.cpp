#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 9999999

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int xdes, ydes, rxdes, rydes;
	int n;
	ll bestprice = 999999999999;
	while(scanf("%d %d %d %d", &xdes, &ydes, &rxdes, &rydes) == 4){
		scanf("%d", &n);
		ll bestprice = 999999999999;
		int x, y, rx, ry;
		ll price;
		for(int i = 0; i < n; i++){
			scanf("%d %d %d %d %lld", &x, &y, &rx, &ry, &price);
			int numh = 0, numv = 0;
			//testando na horizontal normalmente...
			int numx, numx1, numy, numy1;
			if(xdes%x == 0){
				numx = xdes/x;
			}else if(xdes%x != 0){
				numx = xdes/x;
				numx++;
			}
			if(ydes%y == 0){
				numy = ydes/y;
			}else if(ydes%y != 0){
				numy = ydes/y;
				numy++;
			}
			if(rxdes%rx == 0){
				numx1 = rxdes/rx;
			}else if(rxdes%rx != 0){
				numx1 = rxdes/rx;
				numx1++;
			}
			if(rydes%ry == 0){
				numy1 = rydes/ry;
			}else if(rydes%ry != 0){
				numy1 = rydes/ry;
				numy1++;
			}
			numx = max(numx, numx1);
			numy = max(numy, numy1);
			ll finalprice = (ll)(numx*numy)*price;
			//testando agora o role na vertical....
			int numx2, numx3, numy2, numy3;
			if(xdes%y == 0){
			    numx2 = xdes/y;
			}else{
			    numx2 = xdes/y;
			    numx2++;
			}
			if(ydes%x == 0){
			    numy2 = ydes/x;
			}else{
			    numy2 = ydes/x;
			    numy2++;
			}
			if(rxdes%ry == 0){
			    numx3 = rxdes/ry;
			}else{
			    numx3 = rxdes/ry;
			    numx3++;
			}
			if(rydes%rx == 0){
			    numy3 = rydes/rx;
			}else{
			    numy3 = rydes/rx;
			    numy3++;
			}
			int nx = max(numx2, numx3);
			int ny = max(numy2, numy3);
			ll fp2 = (ll)(nx*ny)*price;
			bestprice = min(bestprice,min(finalprice, fp2));
		}
		printf("%lld\n", bestprice);
	}
    return 0;
}
